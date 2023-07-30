import { showConfirm, showAlert } from "../../modules/confirm.js";
import { setStickySize, setCallback as setStickyCallback } from "../../modules/sticky_fixed.js";
import { getLastElement } from "../../modules/utilities.js";
import { needsMainclass, defaultMainclass, guessLanguage, getAceMode, getMainclassName } from "../../modules/programming_languages.js";
import { sentryBreadcrumb } from "../../modules/sentry.js";

let editor = null;
if(document.querySelector("#editor")) {
    editor = ace.edit("editor");
    editor.setOptions({
        autoScrollEditorIntoView: true,
        copyWithEmptySelection: true,
    });
    editor.setTheme("ace/theme/textmate");
    editor.session.setMode('ace/mode/text');

    const introBookmarkText = jQuery("#editor-bookmark-label").data("intro-text");
    jQuery("#editor-bookmark-label").data('editor-text', introBookmarkText);
    jQuery("#editor-bookmark-label").text(introBookmarkText);

    setStickyCallback(() => { editor.resize(); });
}

let storage = null;
try {
    storage = window.localStorage;
} catch { /* Ignore errors */ }

const initDataset = document.querySelector("#editor-container").dataset;
const problemName = initDataset.problemName;
const submitUrl = initDataset.submitUrl;
const maySubmit = initDataset.maySubmit === 'true';
const sourcelim = initDataset.sourcelim;
const mainclassContainer = document.querySelector("#mainclass-container");

let autoUpdateMainclass = true;
let currentEditContainerActive = "";

let language = {
    defaultExtension: "txt",
    mode: 'text',
    value: '',
    defaultCode: '',
    defaultName: 'untitled'
}
let files = [];
let currentSelectedId = 0;

const languageSelect = document.querySelector("#editor_languages_list");

const dragEditorZone = document.querySelector("#editor-container");
let dropZone = document.querySelector("body");

function getAvailableLanguages() {
    if(!languageSelect) {
        return [];
    }
    const nodeList = languageSelect.querySelectorAll("option");
    const arr = Array.from(nodeList);
    return arr.map((option) => option.value).filter((str) => str != "");
}

const availableLanguages = getAvailableLanguages();

//Get the saved files from the local storaged if available and ask if the user would like to use them
let oldFilesString = null;
try {
    oldFilesString = storage.getItem("kattis_task_" + problemName);
} catch { /* Ignore errors */ }
const oldFiles = JSON.parse(oldFilesString);

if("initializeFromUrl" in initDataset) {
    initFromSubmission(initDataset.initializeFromUrl);
} else if(oldFilesString != null && oldFiles.files.length > 0 && maySubmit) {

    showConfirm(
        "Continue",
        "You have old files for this task. Would you like to use them?",
        function() {
            // oldFiles.mainclass may not exist, but undefined is handled by initFromFiles
            initFromFiles(oldFiles.files, oldFiles.language.value, oldFiles.mainclass);
        },
        null,
        { confirmTitle: "Continue" }
    );
} else {
    showEditorContainer("editor-container-intro");
}

function showEditorContainer(id) {
    sentryBreadcrumb({message: 'showEditorContainer()', data: { id: id } })
    const editorContainers = document.querySelectorAll(".editor-container-content");
    for(const container of editorContainers) {
        if(container.id && container.id == id) {
            if(container.classList.contains("is-hidden")) {
                container.classList.remove("is-hidden");
                currentEditContainerActive = id;
            }

            if(id == "editor-container-editor") {
                createEditorFileEvents();
            }
        } else {
            container.classList.add("is-hidden");
        }
    }

    setStickySize();
}

function startCoding(e) {
    e.preventDefault();
    const target = e.currentTarget;
    const select = target.closest(".editor-container-content").querySelector("#intro_language_select");
    const value = select.value;
    if(value) {
        removeAllFiles();
        setLanguage(value);
        addPage();
        showEditorContainer("editor-container-editor");
    } else {
        showAlert("Language", "Please pick a language.", null, { confirmTitle: "OK"} );
    }
}

function initFromFiles(newFiles, newLanguage, newMainclass) {
    sentryBreadcrumb({message: 'initFromFiles()', data: { newLanguage: newLanguage, newMainclass: newMainclass} })
    removeAllFiles();
    setLanguage(newLanguage);
    for(const file of newFiles) {
        addPage(file.filename, file.code);
    }

    if(newMainclass) {
        mainclassContainer.querySelector("#mainclass").value = newMainclass;
        autoUpdateMainclass = false;
    }
    showEditorContainer("editor-container-editor");
}

// from https://stackoverflow.com/questions/30106476/using-javascripts-atob-to-decode-base64-doesnt-properly-decode-utf-8-strings
function b64DecodeUTF8(str) {
    return decodeURIComponent(atob(str).split('').map(function(c) {
        return '%' + ('00' + c.charCodeAt(0).toString(16)).slice(-2);
    }).join(''));
}

async function initFromSubmission(url) {
    let response;
    try {
        response = await fetch(url, {
            method: 'GET',
            mode: 'same-origin',
            cache: 'no-cache',
            credentials: 'same-origin',
            headers: {
                'Content-Type': 'application/json'
            },
        });
    } catch(error) {
        alert(error);
        return;
    }

    const data = await response.json();
    const language = data.language;
    const mainclass = data.mainclass;
    const files = data.files.map( f => ({
        filename: f.filename,
        code: b64DecodeUTF8(f.data),
    }));
    initFromFiles(files, language, mainclass);
}

//The function that is called when selecting a new language
function setEditorModeEvent(e) {
    const target = e.target;
    const value = target.value;

    if(value == null) {
        console.log("No value");
        return;
    }

    if(value == language.value) {
        return;
    }

    showConfirm(
        "Change language",
        "Changing the language will change the compiler used to judge your submission. Please rename files to have the correct file suffixes for your new language. Are you sure?",
        function() {
            setLanguage(value);
        },
        function() {
            jQuery(languageSelect).val(language.value);
            jQuery(languageSelect).trigger("change");
        },
        {
            confirmTitle: "Change language",
            theme: "danger"
        }
    );


}

function updateMainclass() {
    if(autoUpdateMainclass) {
        mainclassContainer.querySelector("#mainclass").value = defaultMainclass(language.value, files);
    }
}


//Changes the editor mode and saves the language options such as default extension, default name and default code
function setLanguage(newLanguage) {
    sentryBreadcrumb({ message: 'setLanguage', data: { newLanguage: newLanguage, oldLanguage: language } });
    const option = languageSelect.querySelector('option[value="'+ newLanguage +'"]');
    if(!option) return;

    if(needsMainclass(newLanguage)) {
        mainclassContainer.classList.remove("is-hidden");
        jQuery(".mainclass-label").text(getMainclassName(newLanguage));
        autoUpdateMainclass = true;
    } else {
        mainclassContainer.classList.add("is-hidden");
        autoUpdateMainclass = false;
    }

    jQuery("#editor-bookmark-label").data('editor-text', newLanguage);
    jQuery("#editor-bookmark-label").text(newLanguage);

    language.mode = getAceMode(newLanguage);
    language.defaultExtension = option.getAttribute("data-defaultExtension") || "";
    language.defaultName = option.getAttribute("data-defaultName") || "";
    language.defaultCode = option.getAttribute("data-defaultCode") || "";
    language.value = newLanguage;

    if(language.mode) {
        editor.session.setMode(`ace/mode/${language.mode}`);
    }

    jQuery(languageSelect).val(newLanguage);
    jQuery(languageSelect).trigger("change");

    if(files.length) {
        updateMainclass();
    }
    save();
}

function createSession(code) {
    return ace.createEditSession(code, `ace/mode/${language.mode}`);
}

//Adds a new file
function addPage(newFilename = null, newData = null) {
    const template = document.querySelector("#editor-file_template");
    if(template != null) {
        template.parentElement.append(template.content.cloneNode(true));

        const insertedElement = getLastElement(".editor-top-input", template.parentElement);
        const input = insertedElement.querySelector(".editor-top-input-field");
        if(input != null) {
            const id = Math.max(-1, ...files.map(f => f.id)) + 1;
            input.setAttribute("data-id", `${id}`);

            let filename = newFilename || language.defaultName + "." + language.defaultExtension;
            const code = newData || language.defaultCode;
            filename = getUniqueFileName(filename, false);

            files.push({
                filename: filename,
                code: code,
                id: id,
                session: createSession(code),
            });

            input.textContent = filename;
            input.setAttribute("data-pageId", id);

            changePage(id, input);
        }

        updateMainclass();
    }
}

function changeSession(session) {
    editor.setSession(session);
    editor.session.setMode(`ace/mode/${language.mode}`);
    editor.session.on('change', onEditorChange);
}

function changePage(_id, pageButton) {
    const id = _id;
    const file = getFileById(id);
    if(file != null) {
        currentSelectedId = file.id;

        changeSession(file.session);
        resetCurrentPageHighlight();
        pageButton.closest(".editor-top-input").classList.add("is-editor-top-input-active");
    }

}

function changePageEvent(e) {
    const target = e.currentTarget.querySelector(".editor-top-input-field");
    const buttonId = target.getAttribute("data-pageId");
    if(buttonId != null && currentSelectedId != buttonId) {
        changePage(buttonId, e.target);
        e.target.blur();
    }
}

//Remove the current graphical page selection indicator
function resetCurrentPageHighlight() {
    const currentlySelected = document.querySelector(".is-editor-top-input-active");
    if(currentlySelected != null) {
        currentlySelected.classList.remove("is-editor-top-input-active");
    }
}

function onEditorChange(delta) {
    updateFile({code: editor.session.getValue()});
}

function onFileRename(e) {
    const selectionStart = window.getSelection().anchorOffset;

    const fixedValue = e.target.textContent;
    let validatedName = getUniqueFileName(fixedValue);

    if(validatedName == "") {
        validatedName = "no_name";
    }

    e.target.innerHTML = validatedName;


    //Set the cursor at the position it was before the text was altered above
    const range = document.createRange();
    range.setStart(e.target.firstChild, selectionStart);
    range.setEnd(e.target.firstChild, selectionStart);
    window.getSelection().removeAllRanges();
    window.getSelection().addRange(range)

    updateFile({filename: validatedName});
    updateMainclass();
}

function getExtension(filename) {
    const regex = /(?:\.([^.]+))?$/;
    return regex.exec(filename)[1];
}

function getNameWithoutExtension(filename, extension) {
    return filename.substring(0, filename.length - extension.length - 1);
}

function updateFile(args) {
    let file = getFileById(currentSelectedId);
    if(file != null) {
        const newFile = { ...file, ...args };
        const fileIndex = getFileIndex(currentSelectedId);
        files[fileIndex] = newFile;
        save();
        updateMainclass();
    }

}

function getFileById(id) {
    return files.find((f) => f != null && f.id == id);
}

function getFileIndex(id) {
    return files.findIndex((f) => f != null && f.id == id);
}

function save() {
    //New array in order to make it a new array/object
    const saveFiles = [];
    for(const file of files) {
        if(file == null) continue;
        const code = file.session.getValue();
        saveFiles.push({
            ...file,
            code: code,
            session: null,
        });
    }

    const toSave = {
        files: saveFiles,
        language: language,
    }
    if(!autoUpdateMainclass) {
        toSave['mainclass'] = document.querySelector("#mainclass").value;
    }
    try {
        storage.setItem("kattis_task_" + problemName, JSON.stringify(toSave));
    } catch {
        // Ignore errors.
    }
}

function getUniqueFileName(value, alertUser = true) {
    let exists = files.filter((file) => file.filename == value);

    if(exists.length == 0) {
        return value;
    }

    if(alertUser) {
        alert("The name already exists.");
    }

    let filenameParts = value.split(".");
    const idx = filenameParts.length == 1 ? 0 : filenameParts.length - 2;
    const originalFilenamePart = filenameParts[idx];
    let newName = '';

    for(let i = 2; exists.length > 0; ++i) {
        filenameParts[idx] = `${originalFilenamePart}${i}`;
        newName = filenameParts.join(".");
        exists = files.filter((file) => file.filename == newName);
    }

    return newName;
}

function removeFileEvent(e) {
    const input = e.currentTarget.closest(".editor-top-input").querySelector(".editor-top-input-field");
    if(input) {
        const id = input.getAttribute("data-pageId");
        if(id) {
            const file = getFileById(id);
            if(file) {
                const fileName = file ? file.filename : "";
                showConfirm(
                    "Delete file",
                    "Are you sure you want to remove the file " + fileName + "? This cannot be undone.",
                    function() {
                        removeFile(id);
                    },
                    null,
                    {
                        confirmTitle: "Continue",
                        theme: "danger"
                    }
                );
            }
        }
    }

}

function removeFile(id) {
    const index = files.findIndex((f) => f != null && f.id == id);
    if(files[index] != null && files.length > 0) {
        files.splice(index, 1);
        save();
        const pagesParent = document.querySelector(".editor-top-pages");
        if(pagesParent != null) {
            const input = pagesParent.querySelector(".editor-top-input-field[data-pageId='" + id + "']");
            if(input != null) {
                const firstWithContent = files.find((f) => f != null);
                if(currentSelectedId == id) {
                    if(firstWithContent === undefined) {
                        const introBookmarkText = jQuery("#editor-bookmark-label").data("intro-text");
                        jQuery("#editor-bookmark-label").data('editor-text', introBookmarkText);
                        jQuery("#editor-bookmark-label").text(introBookmarkText);
                        showEditorContainer("editor-container-intro");
                    } else {
                        const firstId = firstWithContent.id || 0;
                        const newInput = document.querySelector(".editor-top-input-field[data-pageId='" + firstId + "']");
                        changePage(firstId, newInput);
                        updateMainclass();
                    }
                }
                input.closest(".editor-top-input").remove();
            }
        }
    }
}

function removeAllFiles() {
    for(const file of files) {
        if(file != null) {
            const input = document.querySelector(".editor-top-input-field[data-pageId='" + file.id + "']");
            if(input != null) {
                input.closest(".editor-top-input").remove();
            }
        }
    }

    files = [];
    autoUpdateMainclass = true;
}

function onFileUpload(e) {
    if(this.files.length === 0) {
        return;
    }

    handleFiles(this.files);
    e.target.value = "";
}

//Handles file uploads both by dropping and by uploading via a button
function handleFiles(files) {
    let promises = [];

    for(const file of files) {
        let filePromise = new Promise(resolve => {
            let reader = new FileReader();
            reader.readAsText(file);
            reader.onload = () => resolve({
                content: reader.result,
                meta: file,
            });
        });
        promises.push(filePromise);
    }

    Promise.all(promises).then(fileContents => {
        if(currentEditContainerActive == "editor-container-editor") {
            createPageFromFileContent(fileContents);
        } else {
            removeAllFiles();

            const fileData = createPageFromFileContent(fileContents);

            if(fileData && Array.isArray(fileData)) {
                const guessedLanguage = guessLanguage(availableLanguages, fileData);
                if(!guessedLanguage) {
                    alert("Unable to guess language from the files you uploaded. Please manually select a language.");
                } else {
                    setLanguage(guessedLanguage);
                }
            }
            showEditorContainer("editor-container-editor")
        }



    });
}

function codeIsOk(filename, extension, code) {
  return true;
}

function totalFileSize(files) {
    return files.reduce((partialSum, file) => partialSum + file.code.length, 0);
}

async function submitCode() {
    const submitButton = document.querySelector("#submit_code_button");
    const filesToSend = [];
    const mainclass = document.querySelector("#mainclass").value;

    submitButton.disabled = true;

    if(files) {
        for(const file of files) {
            //Do pre-checking
            if(!codeIsOk(file.filename, file.extension, file.code)) {
                showAlert("Error", "Your code had a problem. Could not submit.", null, {
                    confirmTitle: "Close",
                    theme: "neutral",
                });
                submitButton.disabled = false;
                return;
            } else {
                filesToSend.push({
                    ...file,
                    session: null,
                });
            }
        }

        if(totalFileSize(filesToSend) > sourcelim) {
            showAlert("Error", `Your code is too large (${totalFileSize(filesToSend)} bytes). The limit is ${sourcelim} bytes. Could not submit.`, null, {
                confirmTitle: "Close",
                theme: "neutral",
            });
            submitButton.disabled = false;
            return;
        }
    }


    /**
     * filesToSend array example:
     * [{
     *  filename: index.js, code: "//Code here", id: 1, session: null
     * }]
     */
    const submitObj = {
        files: filesToSend,
        language: language.value,
        mainclass: mainclass,
        problem: problemName,
    };

    let response;
    try {
        response = await fetch(submitUrl, {
            method: 'POST',
            mode: 'same-origin',
            cache: 'no-cache',
            credentials: 'same-origin',
            headers: {
                'Content-Type': 'application/json',
                'Accept': 'application/json'
            },
            body: JSON.stringify(submitObj)
        });
    } catch(error) {
        alert(error);
        submitButton.disabled = false;
        return;
    }
    sentryBreadcrumb({ message: 'submitCode() fetch response', data: { status: response.status } });

    const body = await response.text();
    sentryBreadcrumb({ message: 'submitCode() fetch body', data: { body } });
    const data = JSON.parse(body);

    if(data['success']) {
        try {
            storage.removeItem("kattis_task_" + problemName);
        } catch {
            // Ignore errors.
        }
        document.location = data['success_url'];
    } else {
        alert("Error:\n" + data['error_messages'].join('\n'));
        submitButton.disabled = false;
    }
}

function createPageFromFileContent(fileContents) {
    for(const file of fileContents) {
        addPage(file.meta.name, file.content);
        save();
    }
    return files;
}

//When dropping files on the page
function onFileDrop(e) {
    e.preventDefault()
    e.stopPropagation()

    //Activate pointer events, the dragging is done.
    dropZone.classList.remove("is-dragging-in-progress");

    const highlight = dropZone.querySelector(".editor-drag_highlight");
    if(!highlight.classList.contains("is-hidden")) {
        highlight.classList.add("is-hidden");
    }
    if(highlight.classList.contains("editor-drag_highlight-intense")) {
        highlight.classList.remove("editor-drag_highlight-intense");
    }

    const dt = e.dataTransfer
    const files = dt.files

    handleFiles(files);
}

//When dragging and leaving the page
function onFileDragLeave(e) {
    e.preventDefault()
    e.stopPropagation()

    //If the current target is the body, it means the leave event is from the body and not a child element. Allow pointer events again. Otherwise flickering would occur.
    if(e.target == dropZone) {
        dropZone.classList.remove("is-dragging-in-progress");
    }

    const highlight = dropZone.querySelector(".editor-drag_highlight");
    if(!highlight.classList.contains("is-hidden")) {
        highlight.classList.add("is-hidden");
    }
    if(highlight.classList.contains("editor-drag_highlight-intense")) {
        highlight.classList.remove("editor-drag_highlight-intense");
    }


}

//When dragging files over the page
function onFileDragOver(e) {
    e.preventDefault()
    e.stopPropagation()

    //A class that disable pointer events for all elements. Prevents flickering.
    dropZone.classList.add("is-dragging-in-progress");

    const highlight = dropZone.querySelector(".editor-drag_highlight");
    if(highlight.classList.contains("is-hidden")) {
        highlight.classList.remove("is-hidden");
    }
}

//When dragging over the editor
function onFileEditorDragOver(e) {
    e.preventDefault()
    e.stopPropagation()

    const highlight = document.querySelector(".editor-drag_highlight");
    if(!highlight.classList.contains("editor-drag_highlight-intense")) {
        highlight.classList.add("editor-drag_highlight-intense");
    }
}

//Called when dragging and leaving the editor
function onFileEditorDragLeave(e) {
    e.preventDefault()
    e.stopPropagation()

    //Remove the intense highlight
    const highlight = dropZone.querySelector(".editor-drag_highlight");
    if(highlight.classList.contains("editor-drag_highlight-intense")) {
        highlight.classList.remove("editor-drag_highlight-intense");
    }

    //If clientX and clientY is 0 it means the user is not hovering over the browser. Disable the overlay and allow pointer events again.
    if(e.clientX == 0 && e.clientY == 0) {
        dropZone.classList.remove("is-dragging-in-progress");
        if(!highlight.classList.contains("is-hidden")) {
            highlight.classList.add("is-hidden");
        }
    }
}

function createEditorFileEvents() {
    const fileUpload = document.querySelector(".editor-top-upload-input");
    if(fileUpload != null) {
        fileUpload.addEventListener("change", onFileUpload);
    }

    //Allow pointer events on the first layer of the editor, in order to capture dragging there and chaning the overlay.
    dragEditorZone.classList.add("is-dragging-unnaffected");

    dropZone = document.querySelector("body");

    if(dropZone != null) {
        dropZone.addEventListener("drop", onFileDrop);
        dropZone.addEventListener("dragleave", onFileDragLeave);
        dropZone.addEventListener("dragover", onFileDragOver);
        dropZone.addEventListener("dragenter", onFileDragOver);
        dragEditorZone.addEventListener("dragover", onFileEditorDragOver);
        dragEditorZone.addEventListener("dragleave", onFileEditorDragLeave);
    }
}

function toggleTab(tabIdToOpen, tabIdToClose) {
    if (tabIdToOpen == tabIdToClose) return;

    const tabToOpen = document.getElementById(tabIdToOpen);
    const tabToClose = document.getElementById(tabIdToClose)
    tabToOpen.classList.remove('is-hidden');
    tabToClose.classList.add('is-hidden');

    const label = jQuery("#editor-bookmark-label");
    if (tabIdToOpen == 'edit-and-submit-tab') {
        label.text(label.data('editor-text'));
    } else {
        label.text(tabToOpen.dataset.bookmarkLabel);
    }
}

function initSubmit() {
    const fileUpload = document.querySelector(".upload_files_button-input");
    if(fileUpload != null) {
        fileUpload.addEventListener("change", onFileUpload);
    }

    //Allow pointer events on the first layer of the editor, in order to capture dragging there and chaning the overlay.
    dragEditorZone.classList.add("is-dragging-unnaffected");

    dropZone = document.querySelector("#editor-container-intro");

    if(dropZone != null) {
        dropZone.addEventListener("drop", onFileDrop);
        dropZone.addEventListener("dragleave", onFileDragLeave);
        dropZone.addEventListener("dragover", onFileDragOver);
        dropZone.addEventListener("dragenter", onFileDragOver);
        //dragEditorZone.addEventListener("dragover", onFileEditorDragOver);
        //dragEditorZone.addEventListener("dragleave", onFileEditorDragLeave);
    }

    const submitButton = document.querySelector("#submit_code_button");
    if(submitButton) {
        submitButton.addEventListener("click", submitCode);
    }
}

function init() {
    const tabButtons = document.getElementsByClassName("tab-nav-js");
    for (const button of tabButtons) {
        button.addEventListener("click", () => {
            toggleTab(button.dataset.tabIdToOpen, button.dataset.tabIdToClose);
        });
    }

    const tabSelectMobile = document.getElementsByClassName("tab-select-js");
    for (const select of tabSelectMobile) {
        select.addEventListener("change", ({target}) => {
            toggleTab(...target.value.split('/'));
            select.value = select.dataset.defaultValue;
        });
    }
}


//Select2 setup
jQuery(document).ready(function() {
    init();

    if(!maySubmit) {
        return;
    }

    jQuery("#editor_languages_list").on("change", function(e) {
        setEditorModeEvent(e);
    });

    jQuery("#editor-add_page-button").on("click", function(e) {
        e.preventDefault();
        addPage();
    })

    jQuery(document).on("click", ".editor-top-input", function(e) {
        e.preventDefault();
        changePageEvent(e);
    })

    jQuery(document).on("click", ".editor-top-input-remove", function(e) {
        e.preventDefault();
        e.stopPropagation();
        removeFileEvent(e);
    })

    jQuery(document).on("input", ".editor-top-input-field", function(e) {
        e.preventDefault();
        onFileRename(e);
    })

    jQuery(document).on("input", "#mainclass", function(e) {
        autoUpdateMainclass = false;
        save();
    })

    jQuery(document).on("keydown", ".editor-top-input-field", function(e) {
        if(e.keyCode == 13) {
            e.preventDefault();
            return false;
        }
    })

    const startCodingButton = document.querySelector("#start_coding_button");
    if(startCodingButton) startCodingButton.addEventListener("click", startCoding);

    initSubmit();
})
