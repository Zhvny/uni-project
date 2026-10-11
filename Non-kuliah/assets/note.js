/* note.js — catatan belajar: Mermaid (lazy), tombol salin, details saat print.
   Kontrak: spec §9. Tanpa eval, tanpa fetch, tanpa state. */
(function () {
  'use strict';

  // Basis aset dari lokasi note.js sendiri (benar di kedalaman mana pun)
  var self = document.currentScript || document.querySelector('script[src$="note.js"]');
  var assetsBase = self && self.src ? self.src.replace(/note\.js(\?.*)?$/i, '') : './assets/';

  // (4) highlight.js dari <head>
  if (window.hljs) { window.hljs.highlightAll(); }

  // (2) tombol salin per pre > code
  function copyText(text, btn) {
    var restore = function () { btn.textContent = 'Copy'; };
    var done = function () { btn.textContent = 'Tersalin'; setTimeout(restore, 1500); };
    var fallback = function () {
      var ta = document.createElement('textarea');
      ta.value = text;
      ta.setAttribute('readonly', '');
      ta.style.position = 'fixed';
      ta.style.top = '-1000px';
      document.body.appendChild(ta);
      ta.select();
      try { document.execCommand('copy'); done(); } catch (e) { /* diam */ }
      document.body.removeChild(ta);
    };
    if (navigator.clipboard && navigator.clipboard.writeText) {
      navigator.clipboard.writeText(text).then(done, fallback);
    } else { fallback(); }
  }

  var codes = document.querySelectorAll('pre > code');
  for (var i = 0; i < codes.length; i++) {
    (function (code) {
      var pre = code.parentElement;
      var wrap = document.createElement('div');
      wrap.className = 'code-wrap';
      pre.parentNode.insertBefore(wrap, pre);
      wrap.appendChild(pre);

      var btn = document.createElement('button');
      btn.type = 'button';
      btn.className = 'copy-btn';
      btn.textContent = 'Copy';
      btn.addEventListener('click', function () { copyText(code.textContent, btn); });
      wrap.appendChild(btn);
    })(codes[i]);
  }

  // (3) buka semua <details> saat print (CSS tidak bisa)
  window.addEventListener('beforeprint', function () {
    var all = document.querySelectorAll('details');
    for (var j = 0; j < all.length; j++) { all[j].open = true; }
  });

  // (1) Mermaid — lazy + run eksplisit (startOnLoad:false; hindari race RF7)
  if (document.querySelector('.mermaid')) {
    var s = document.createElement('script');
    s.src = assetsBase + 'mermaid/mermaid.min.js';
    s.onload = function () {
      try {
        window.mermaid.initialize({ startOnLoad: false });
        window.mermaid.run({ querySelector: '.mermaid' });
      } catch (e) { /* diam: biarkan <pre class="mermaid"> terbaca mentah */ }
    };
    document.head.appendChild(s);
  }
})();
