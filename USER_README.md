# User guide: making mods for Dragon Ball Z: The Legacy of Goku

You can change all of the game's text and its compressed graphics, build a playable ROM, and share it as a patch,
without knowing assembly or C.

## 1. Setup (once)
```sh
sudo apt-get install git make python3 python3-pip gcc gcc-arm-none-eabi binutils-arm-none-eabi libmgba-dev libpng-dev zlib1g-dev
pip install --break-system-packages capstone numpy pillow unicorn
git clone https://github.com/smh4004/log1-decomp && cd log1-decomp
cp /path/to/your/Legacy_of_Goku_USA.gba baserom.gba
make && make compare            # must print: log1.gba: OK
```
`baserom.gba` must be the stand-alone USA ROM, SHA-1 `a3c8c76742f11fc6a3f6e3fcca20992458cac0b5` (not the "2 Games in 1"
compilation).

## 2. The edit loop
```sh
make extract        # once: unpacks the game into assets/
# ... edit files in assets/ ...
make modern         # builds log1_modern.gba from your edits
make patch          # when you're ready to share: log1_modern.bps
```
With no changes, `make modern` produces the original ROM exactly. Never publish `assets/` or a ROM; publish the `.bps`.

## 3. Text (`assets/text/strings.txt`)
Every string the game points to, one per line: `LABEL<TAB>text`. Find a line with
`grep -n "words from the line" assets/text/strings.txt`, change the text after the tab, keep the label.
* Any length: longer text moves automatically. Keep text boxes readable (the game wraps lines itself).
* `{0A}` = line break, `{{` = a literal `{`. Keep `%d`/`%s` where they appear.
* Names, menu items, technique names and dialogue are all in this file.

## 4. Graphics (`assets/gfx/blocks/`)
Each compressed block is two files:
* `LABEL.png`: the data drawn as 4-bit tiles (16 per row). The 16 grey levels are palette indexes 0-15 (black = 0,
  white = 15). Edit with any editor that keeps the image size; draw with those 16 greys (indexed PNG recommended).
* `LABEL.bin`: the raw unpacked bytes (for data that isn't tiles: maps, tables). Edit either file, not both.
The build re-packs a changed block the way the game expects (Huffman / LZ77 / run-length). Example: the title logo is
`gUnknown_084DEDE4`. To find which block a screen uses, change one block (e.g. fill it with 15) and look.

## 5. Testing and sharing
* Play `log1_modern.gba` in mGBA.
* `make verify-mods` runs the toolkit self-test; `python3 tools/assets/demo_edits.py` (on a fresh extract) shows one text and
  one graphics edit.
* `make patch` -> `log1_modern.bps`. Players apply it to their own ROM with any BPS patcher or
  `python3 tools/bps.py apply original.gba log1_modern.bps out.gba`.

## 6. Limits
* No editors yet for maps, palettes, music or the intro movies (see `docs/progress.md`).
* Graphics keep their unpacked size.
