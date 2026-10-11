# NOTE-SPEC — kontrak agent untuk catatan

Satu-satunya dokumen yang dibaca agent saat **membuat** atau **meng-update** catatan.
Sumber kerangka: `Non-kuliah/_templates/note.html` — **salin mentah**, jangan mengarang struktur.

Lokasi file: `Non-kuliah/<subjek>/<topik>.html` (kedalaman 2 — path aset `../assets/…`).

---

## 1. Blok #0–#10 (kelas adalah kontrak)

Setiap catatan = satu `<article>` berisi urutan blok. **Wajib:** #0, #1, #3, #6, #10.
**Opsional** (hapus bila tidak relevan): #2, #4, #5, #7, #8, #9.

| # | Blok | Kelas | Wajib? |
|---|---|---|---|
| 0 | Meta (masthead) | `header.meta` + back-link + `p.eyebrow` (subjek) + `h1` (topik) + `dl` (prasyarat, dibuat, status, estimasi baca) | ✅ |
| 1 | TL;DR | `section.tldr` (maks 5 baris) | ✅ |
| 2 | Peta konsep | `figure.map` + `pre.mermaid` atau SVG inline | — |
| 3 | Konsep inti | `section.concept` (1 blok = 1 ide) + `aside.pitfall` | ✅ |
| 4 | Rumus | `section.formula` (LaTeX + tabel simbol + kapan pakai) | — |
| 5 | Kode | `section.code` + `pre > code.language-…` | — |
| 6 | Latihan | `section.practice` + `<details><summary>` (min **1** soal) | ✅ |
| 7 | Jebakan & FAQ | `section.faq` | — |
| 8 | Glosarium | `section.glossary` + `dl` + `dt`/`dd` (**bukan tabel**) | — |
| 9 | Checklist | `section.checklist` + `ul` | — |
| 10 | Sumber | `section.sources` + `ol` | ✅ |

Contoh potongan (sesuai `_templates/note.html`):

```html
<header class="meta">
  <a class="back" href="../index.html">&larr; Daftar catatan</a>
  <p class="eyebrow">Bisnis</p>
  <h1>Break-even point</h1>
  <dl>
    <dt>Prasyarat</dt><dd><a href="../bisnis/biaya-tetap-variabel.html">biaya tetap &amp; variabel</a></dd>
    <dt>Dibuat</dt><dd>2026-10-11</dd>
    <dt>Status</dt><dd>solid</dd>
    <dt>Estimasi baca</dt><dd>15 menit</dd>
  </dl>
</header>

<section class="tldr"><h2>TL;DR</h2><ul><li>…</li></ul></section>

<section class="concept">
  <h2>Konsep inti</h2>
  <h3>Judul ide</h3>
  <p>Definisi 1 kalimat …</p>
  <p>Kenapa penting …</p>
  <aside class="pitfall"><p>Miskonsepsi umum …</p></aside>
</section>

<section class="formula">
  <h2>Rumus</h2>
  <p>$$ BEP_{unit} = \frac{FC}{P - VC} $$</p>
  <table><thead><tr><th>Simbol</th><th>Arti</th></tr></thead>
  <tbody><tr><td>\(FC\)</td><td>Total biaya tetap</td></tr></tbody></table>
  <p><strong>Kapan dipakai:</strong> …</p>
  <p><strong>Kapan tidak:</strong> …</p>
</section>

<section class="practice">
  <h2>Latihan mandiri</h2>
  <p>1. Soal …</p>
  <details><summary>Lihat jawaban</summary><p>Jawaban …</p></details>
</section>

<section class="sources"><h2>Sumber</h2><ol><li>…</li></ol></section>
```

Di dalam `.layout`, **sebelum** `<article>`, ada daftar isi (salin dari template):

```html
<details class="toc">
  <summary>Daftar isi</summary>
  <nav aria-label="Daftar isi"><ol><li><a href="#tldr">TL;DR</a></li>…</ol></nav>
</details>
```

Aturan isi: bahasa prosa **Indonesia** (istilah teknis tetap Inggris); 1 blok konsep = 1 ide;
setiap rumus **wajib** punya "kapan dipakai / kapan tidak"; jawaban latihan **wajib** `<details>`.

---

## 2. Kelas yang diizinkan + larangan gaya inline

- **Hanya** kelas di tabel §1 (dan `details.toc` + `summary`, `aside.pitfall`, `dl/dt/dd`, `p.eyebrow`, `a.back`, `pre > code`).
- **Dilarang** atribut `style="…"`. Semua gaya berasal dari `assets/note.css`.
- **Dilarang** menambah elemen/kelas baru; kalau butuh sesuatu yang belum ada, hentikan
  dan laporkan (jangan mengarang CSS).

---

## 3. LaTeX: macro boleh + config MathJax (v4)

- Delimiter inline: `\( … \)` · display: `$$ … $$`.
- **PENTING — backslash body SATU, config DUA.** Di **body** HTML tulis `\(x\)` (satu backslash). Di **config JS** tulis `[['\\(','\\)']]` (dua backslash; JS men-unescape). Bila body tertulis `\\(x\\)` (dua backslash), MathJax menganggap delimiter ter-escape dan **inline tidak dirender tanpa error** (jebakan senyap). Self-check §8 butir 4/5 memverifikasinya.
- Hanya macro yang **sudah dibundel** di `tex-svg.js`: paket `ams`, `newcommand`, `configmacros`, `textmacros`.
  **Dilarang** `\require` atau paket yang butuh unduh modul (`\cancel`, `\ce`, dll.).
- **`throwOnError` tidak boleh diset** — opsi itu **dihapus di MathJax v4** dan menghasilkan warning.
  Config yang benar (sudah ada di template, salin apa adanya):

```html
<script>
window.MathJax = {
  tex: { inlineMath: [['\\(','\\)']], displayMath: [['$$','$$']] },
  svg: { fontCache: 'global' },
  options: {
    enableSpeech: false,
    enableBraille: false,
    menuOptions: {
      settings: { enrich: false, speech: false, braille: false, assistiveMml: false }
    }
  }
};
</script>
```

- Diagram: `<pre class="mermaid">` berisi sintaks Mermaid. **Jangan** `sequenceDiagram`,
  `gantt`, atau `mindmap` (butuh modul lazy yang tidak tersedia offline di `file://`).

---

## 4. Langkah wajib: daftarkan di `index.html`

Setelah catatan dibuat, tambahkan **satu** `<li>` ke `<ul id="notes">` di `Non-kuliah/index.html`:

```html
<li data-subjek="bisnis" data-tag="bep,biaya,keuangan">
  <a href="bisnis/bep-break-even.html">Break-even point</a>
  <span class="tags">bisnis · bep, biaya · 2026-10-11</span>
</li>
```

`data-subjek` dan `data-tag` **wajib** (dipakai filter). Path `href` relatif dari `index.html`.

---

## 5. Penamaan

- Folder subjek: huruf kecil, tanpa spasi (`bisnis/`, `statistika/`, `pemrograman/`).
- File: kebab-case (`bep-break-even.html`, `uji-t-satu-sampel.html`).
- Tautan antar catatan: relatif (`../statistika/uji-t-satu-sampel.html`).
- Gambar: di `<subjek>/img/`, format `.png`/`.svg`, **wajib** `alt`.

---

## 6. Kriteria selesai

Sebuah catatan selesai bila:
1. blok **wajib #0, #1, #3, #6, #10** ada;
2. latihan berisi **≥ 1 soal** dengan jawaban `<details>`;
3. setiap rumus punya "kapan dipakai" (dan idealnya "kapan tidak");
4. ada baris `<li>` di `index.html` (§4);
5. lolos batas cetak (§7) dan self-check (§8).

---

## 7. Batas cetak (B5 = lebar isi 136 mm)

| Aspek | Batas |
|---|---|
| Baris kode | **≤ 72 karakter** (Consolas 82/baris, Courier New 75/baris) |
| Rumus display | **≤ ±60 karakter** per baris; pecah dengan `\begin{aligned}` |
| Tabel 2 kolom | isi sel **≤ 40 karakter** |
| Tabel 3 kolom | isi sel **≤ 25 karakter** |
| Warna | **Tidak boleh** ada informasi yang hanya terbaca dari `background-color` (Chrome tidak mencetak latar secara default) |

Bahasa kode yang diizinkan: `python`, `javascript`, `bash`, `sql`, `json`, `html`, `css`,
`markdown`, `ini`, `yaml`, `powershell`.

---

## 8. Self-check (jalankan sebelum menyatakan selesai)

```bash
# 1) baris kode terpanjang dalam file (harus <= 72)
awk '/<code/{f=1} f{print length($0)} /<\/code>/{f=0}' <file>.html | sort -n | tail -1

# 2) baris terpanjang di dalam blok kode saja
python - <<'PY'
import re,sys
s=open(sys.argv[1],encoding='utf-8').read()
for m in re.findall(r'<code[^>]*>(.*?)</code>', s, re.S):
    print('max code line:', max((len(l) for l in m.splitlines()), default=0))
PY
<file>.html

# 3) sel tabel terpanjang (harus <= 40 utk 2 kolom, <= 25 utk 3 kolom)
grep -oP '(?<=<td>)[^<]*' <file>.html | awk '{print length}' | sort -n | tail -1

# 4) backslash body ganda (jebakan senyap) — HARUS 0 kecuali baris config inlineMath
grep -n '\\\\(' <file>.html | grep -v inlineMath || echo "OK: tidak ada \\( ganda di body"

# 5) cepat: hitung ekspresi inline mentah yang tak ter-render (jalankan di browser console)
#    document.body.innerText.match(/\\\(/g)?.length || 0   -> harus 0
```

Buka di browser: periksa console bersih, rumus/diagram/highlight muncul.

---

## 9. Cara UPDATE (dilarang regenerate penuh)

Perintah "update catatan X" / "ulas topik X":

1. **Baca** file catatan yang ada dari disk.
2. **Edit di tempat** — pertahankan blok yang sudah ada; tambah/ubah hanya bagian yang diminta
   (mis. tambah 1 FAQ, perbaiki 1 rumus). **Jangan** menulis ulang seluruh file.
3. Pertahankan blok **wajib** tetap ada; jangan menghapus blok yang tidak diminta.
4. Jalankan **self-check** (§8) + buka di browser (console bersih).
5. Tambahkan **satu entri** ke `#review-entries` di `Non-kuliah/index.html`:
   `<li>YYYY-MM-DD — <topik> — <catatan perubahan></li>`.
6. **Commit** perubahan.
