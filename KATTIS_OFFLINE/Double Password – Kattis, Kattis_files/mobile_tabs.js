jQuery(document).ready(() => {
  const $ = jQuery;
  $(".tab-nav").each((index, elem) => {
    const items = $(".tab-nav-item", elem);
    const select = $(document.createElement("select"));
    const selectClasses = $(elem).data("mobile-select-classes");

    select.addClass(selectClasses);

    $(elem).after(select);

    function addOption(item, selectElem) {
      const option = $(document.createElement("option"));
      const linkText = $(item).text();
      const isActive = $(item).hasClass("active");
      const isJsLink = $(selectElem).hasClass("tab-select-js");

      if (isJsLink) {
        option.val(item.dataset.tabIdToOpen + '/' + item.dataset.tabIdToClose);
      } else {
        option.val(item.href);
      }

      option.text(linkText);

      if (isActive) {
        option.attr("selected", "selected");
      }

      selectElem.append(option);
    }

    items.each((i, item) => {
      if ($(item).hasClass('tab-nav-dropdown')) {
        const optionGroup = $(document.createElement("optgroup"));
        const optionGroupName = $(item).data('mobile-tab-name');
        optionGroup.attr('label', optionGroupName);

        select.append(optionGroup);
        const dropdownItems = $(".dropdown-item", item);

        dropdownItems.each((k, dropdownItem) => {
          addOption(dropdownItem, optionGroup);
        });
      } else {
        addOption(item, select);
      }
    });

    select.attr('data-default-value', select.val());

    function onSelectChange({ value }) {
      window.location.assign(value);
    }

    const isJsLink = $(select).hasClass("tab-select-js");
    if (!isJsLink) {
      $(select).on("change", ({ target }) => {
        onSelectChange(target);
      });
    }

    $('.tab-nav-dropdown', elem).click(function (e) {
      $('.tab-nav-dropdown', elem).removeClass('open'); // close all other dropdowns
      $(this).addClass('open');
      e.stopPropagation();
    });

    $(document).mouseup((e) => {
      const container = $('.tab-nav-dropdown', elem);
      // if the target of the click isn't the container nor a descendant of the container
      if (!container.is(e.target) && container.has(e.target).length === 0) {
          container.removeClass('open');
      }
    });
  });
});
