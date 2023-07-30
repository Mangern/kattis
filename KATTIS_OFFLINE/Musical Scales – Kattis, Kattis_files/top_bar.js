import { addCloseFunction } from "../../modules/tooltip.js";
import "../../modules/timer.js";

function fixContentPadding() {
  const root = document.documentElement;
  const topBar = document.querySelector(".top_bar");
  if(topBar) {
    const topBarHeight = topBar.clientHeight;
    let topBarHeightFixed = topBarHeight;

    if(window.innerWidth < 720 || isBannerActive()) {
      topBarHeightFixed = 0;
    }
    root.style.setProperty("--main-padding-y", (topBarHeightFixed + 23) + "px");
    root.style.setProperty("--top_bar-height", topBarHeight + "px");
  }
}

function isBannerActive() {
  const banner = document.querySelector(".banner");
  if(banner) {
    if(banner.clientHeight > 0) {
      return true;
    }
  }
  return false;
}

window.addEventListener("resize", fixContentPadding);

window.addEventListener('load', (event) => {
  fixContentPadding();
});

const banners = document.querySelectorAll(".banner");
if(banners) {
  for(const banner of banners) {
    banner.querySelector("button")?.addEventListener("click", function(e) {
      fixContentPadding();
    });
  }
}

const buttons = document.querySelectorAll(".top_bar-button");
if(buttons) {
  for(const button of buttons) {
    button.addEventListener("click", function(e) {
      e.currentTarget.classList.add("top_bar-button-selected");
    });
  }
}

addCloseFunction(function() {
  const selected = document.querySelectorAll(".top_bar-button-selected");
  if(selected) {
    for(const button of selected) {
      button.classList.remove("top_bar-button-selected");
    }
  }
});
