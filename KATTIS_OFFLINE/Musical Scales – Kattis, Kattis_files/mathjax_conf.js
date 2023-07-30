window.MathJax = {
  options: {
    ignoreHtmlClass: ".*",
    processHtmlClass: 'tex2jax_process'
  },
  tex: {
    inlineMath: [['$','$'], ['\\(','\\)']],
    autoload: {
      color: [],
      colorv2: ['color']
    },
    packages: { '[+]': ['noerrors'] }
  },
  loader: {
    load: ['[tex]/noerrors']
  }
};
