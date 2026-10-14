# Non-kuliah — Sistem Catatan Belajar (offline)

Catatan: HTML statis offline (`file://`), library terpusat di `assets/`, satu topik = satu file di folder subjek. Kontrak agent: `NOTE-SPEC.md`. Daftar: `index.html`.

Catatan kuliah (per sesi, format Markdown siap import Notion) ada di `Semester_*/<Mata Kuliah>/Notion/*.md`, mis. `Semester_5/Cloud Interfacing with Virtualization/Notion/`.

## Library (versi terpin)

| Library | Versi | File | Ukuran | Sumber |
|---|---|---|---|---|
| MathJax | 4.1.3 | `assets/mathjax/tex-svg.js` | 1806 KB | `https://cdn.jsdelivr.net/npm/mathjax@4.1.3/tex-svg.js` |
| Mermaid | 11.16.1 | `assets/mermaid/mermaid.min.js` (UMD) | 3482 KB | `https://cdn.jsdelivr.net/npm/mermaid@11.16.1/dist/mermaid.min.js` |
| highlight.js | 11.12.0 | `assets/hljs/hljs.min.js` (full build) + `github.min.css` + `github-dark.min.css` | 126 KB | build browser resmi `highlightjs/cdn-release@11.12.0/build/` |

**Keputusan hljs:** per-language di npm (`lib/languages/*.js`) ternyata *CommonJS* (`module.exports`) — tidak bisa dimuat via `<script>` di browser. Fallback ke *full build* resmi (semua bahasa, 126 KB). Konsekuensi: bahasa apa pun ter-highlight; daftar 11 bahasa tetap jadi batas authoring di `NOTE-SPEC.md`.

## Bila `assets/` hilang

`assets/` di-ignore git — bila hilang (penghapusan/klon), unduh ulang dari tabel di atas ke path yang sama. Versi jangan diubah tanpa menguji ulang.

## Cara cetak (per catatan)

1. Buka catatan di Chrome → `Ctrl+P`.
2. Kertas: pilih **A4** atau **ISO B5** (176×250 mm) di dialog print.
3. Margin: *Default* (CSS `@page` 16/20 mm sudah mengatur; jangan *fit-to-page*), **duplex** aktif.
4. Centang *Headers and footers* (nomor halaman) — CSS `@page` margin boxes tidak didukung Chrome.
5. Preview: jawaban latihan terbuka otomatis (JS `beforeprint`), latar terang.