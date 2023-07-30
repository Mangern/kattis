document.addEventListener('DOMContentLoaded', () => {
    document.querySelector(".menu_mobile_link").addEventListener("click", () => {
        const header = document.querySelector('.l-page_header');
        if(header.classList.contains("l-page_header-open")) {
            //Close
            header.classList.remove('l-page_header-open');
            document.body.classList.remove("is-mobile_static");

            document.querySelector(".menu_mobile_link_icon").classList.remove("fa-times");
            document.querySelector(".menu_mobile_link_icon").classList.add("fa-bars");
        } else {
            //Open
            header.classList.add('l-page_header-open');
            document.body.classList.add("is-mobile_static");

            document.querySelector(".menu_mobile_link_icon").classList.remove("fa-bars");
            document.querySelector(".menu_mobile_link_icon").classList.add("fa-times");
        }
    });

    const searchForm = document.querySelector("#search_form");
    const searchSubmit = document.querySelector("#search_submit");
    if(searchForm && searchSubmit) {
        searchSubmit.addEventListener("click", onSearchButtonClick);
    }

    function onSearchButtonClick(e) {
        e.preventDefault();
        searchForm.submit();
    }

});
