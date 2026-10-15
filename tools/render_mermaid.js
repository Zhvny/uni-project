// Render diagram Mermaid (UMD lokal, offline) menjadi PNG.
// Pakai: node tools/render_mermaid.js <diagram.mmd> <out.png> [lebar]
// Mengembalikan ukuran PNG via stdout JSON; exit != 0 bila gagal.
const { chromium } = require('C:/Users/Zhvn/AppData/Roaming/npm/node_modules/playwright-core');
const fs = require('fs');
const path = require('path');

const MERMAID_JS = path.join(
  'C:/Users/Zhvn/Documents/SUNIB/Kuliah/Non-kuliah/assets/mermaid/mermaid.min.js');

(async () => {
  const [mmd, out, w] = process.argv.slice(2);
  if (!mmd || !out) throw new Error('pakai: node render_mermaid.js <in.mmd> <out.png>');
  const code = fs.readFileSync(mmd, 'utf8');
  const browser = await chromium.launch();
  const page = await browser.newPage({ viewport: { width: Number(w) || 1100, height: 800 } });
  await page.setContent('<!DOCTYPE html><html><body><div id="c"></div></body></html>');
  await page.addScriptTag({ content: fs.readFileSync(MERMAID_JS, 'utf8') });
  await page.waitForFunction(() => window.mermaid, null, { timeout: 20000 });
  await page.evaluate(async (c) => {
    await window.mermaid.initialize({ startOnLoad: false });
    const r = await window.mermaid.render('d', c);
    document.getElementById('c').innerHTML = r.svg;
  }, code);
  await page.waitForTimeout(900);
  const el = await page.$('#c svg');
  if (!el) throw new Error('mermaid tidak menghasilkan <svg> (sintaks?)');
  await el.screenshot({ path: out });
  await browser.close();
  const kb = Math.round(fs.statSync(out).size / 1024);
  process.stdout.write(JSON.stringify({ png: out, kb }));
})().catch((e) => { process.stderr.write('FAIL ' + String(e).slice(0, 300)); process.exit(1); });
