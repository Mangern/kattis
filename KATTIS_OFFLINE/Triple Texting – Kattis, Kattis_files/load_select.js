jQuery(document).ready(() => {
    // Initialize select2-selectboxes
    jQuery('select.select2, .select2 select').each(function () {
        const select = jQuery(this);
        const classes = select.attr("class")?.replace("select2", "");
        const placeholder = select.attr("data-placeholder");
        const closeOnSelect = select.data("close-on-select");
        const selectAllElementId = select.data("select-all-id");

        select.select2({
            width: select.parents(".select-list").length ? "auto" : "100%",
            dropdownCssClass: classes,
            placeholder: placeholder || null,
            closeOnSelect: closeOnSelect && closeOnSelect !== 'false',
        });

        if (selectAllElementId) {
            const selectAllElem = jQuery(`#${selectAllElementId}`);
            selectAllElem.click(function () {
                const checkbox = jQuery(this);
                if (checkbox.is(':checked')) {
                    jQuery('option', select).prop("selected", "selected");
                } else {
                    select.val(null);
                }
                select.trigger("change");
            });
        }
    });

    // Initialize the onchange-handlers
    jQuery(".is-select2-with-info").each(function () {
        // Initialize the selectbox
        onSelectChange(this);
        // Add the event-handler
        jQuery(this).on("change", (e) => {
            onSelectChange(e.target);
        });
    });

    // Change the text in the infobox on select change
    function onSelectChange(target) {
        const { value } = target;

        if (value == null) {
            console.log("No value");
            return;
        }

        const option = target.querySelector(`option[value="${value}"]`);
        const parent = target.closest("form");
        const infoBox = parent.querySelector(".is-select-information");
        const infoText = option.getAttribute("data-info-text");
        if (option != null && infoText) {
            infoBox.textContent = infoText;
            infoBox.style.display = "flex";
        } else {
            infoBox.style.display = "none";
        }
    }

    // workaround for https://github.com/select2/select2/issues/5993
    jQuery(document).on('select2:open', () => {
        const allFound = document.querySelectorAll('.select2-container--open .select2-search__field');
        if (allFound) {
            allFound[allFound.length - 1].focus();
        }
    });
});
