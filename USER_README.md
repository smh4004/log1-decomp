# User guide: making mods for Dragon Ball Z: The Legacy of Goku

You can change all of the game's text, its compressed graphics and palettes, its maps, who and what is in each area
(characters, enemies, warps), enemy stats and the player's levels, build a playable ROM, and share it as a patch, without knowing assembly or C.

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
* `LABEL.png`: the picture as the game draws it, in its own colours: dialogue faces (32x32), full screens (title,
  logos, story pictures; 240x160) and area tile sets (8x8 tiles, 16 per row). It is an indexed PNG: edit it with an
  editor that keeps indexed colour (Aseprite, GIMP in Indexed mode, GraphicsGale) and draw only with colours from its
  palette. Keep the image size. (If it gets saved as RGB, each pixel becomes the nearest palette colour.)
* `LABEL.bin`: the raw unpacked bytes. Edit either file, not both.
The build re-packs a changed block the way the game expects. Examples: the title screen is `gUnknown_084DEDE4`; faces
are the 32x32 PNGs; Kame House's map tiles are `gUnknown_085C3888` (and `assets/maps/tiles/area00.png` shows all of
that area's tiles as the map uses them).

## 5. Palettes (`assets/palettes/`)
`LABEL.pal` files are plain text (JASC-PAL): after three header lines, one `R G B` line per colour (0-255). Most pixel
editors can load and save them. Keep the number of lines. A palette is shared by everything that uses it (for an area,
its whole map). The area palettes are the ones named in each map's record; to find the one a picture uses, compare its
PNG colours, or look up the image's palette label in `assets/manifest.json`.

## 6. Maps (`assets/maps/areaNN.tmx`)
Open a `.tmx` in [Tiled](https://www.mapeditor.org) (free). Each of the 42 areas has:
* `bg3 (bottom)`, `bg2`, `bg1 (top)`: the three tile layers (paint with tiles from the area's tile set; flips work).
* `walkable`: red = the player can walk there. `mask1` and `mask2` are other masks (hidden; leave them unless you are
  experimenting).
Look at `assets/maps/preview/areaNN.png` to find an area. Keep the map size. An area is made of 30x20-tile screens;
painting into an empty screen fills the rest of that screen with tile 0 (blank). To change how tiles look, edit the
tile set's PNG in `assets/gfx/blocks/`.

## 7. Enemies and levels (`assets/tables/`)
* `enemies.csv`: one row per enemy type: `exp` (EXP you get), `hp`, `defense` (taken off each hit: in full, by half or
  by a quarter, at random), `power`, and 17 AI/movement values (`s10`...) that aren't understood yet.
* `levels.csv`: the player's 25 levels: `exp` needed, `max_hp`, `power`, `ki`.
Edit numbers only; keep the rows. Spreadsheet programs open these files; save as CSV.

## 8. Who and what is in each area (`assets/areas/areaNN.json`)
One JSON text file per area (open with any text editor; keep the commas and brackets valid). Positions are in pixels
(a tile is 8 pixels; the map's tile grid in Tiled shows x/y in tiles, so multiply by 8).
* `actors`: characters and enemies. `sprite` is a name from `assets/areas/SPRITES.txt`. `kind` 2 = enemy (it uses the
  `enemies.csv` row with the same name, e.g. `wolf`); 0 or 1 = a character, `param` = what they say. `show` 0 = always,
  1 = only until story flag `flag` is set, 2 = only after. Copy a line to add one, delete a line to remove one.
* `triggers`: zones (`rect` = x1, y1, x2, y2). `warp` takes the player to `to_area` at `to_x`, `to_y`; `hp_zone`
  changes HP by `hp` every second inside it; `event` starts a conversation; `message` shows a text. Edit the numbers,
  or add a new `warp`/`hp_zone`/`event` line without a `label`. Example (a warp to the forest by Goku's house):
  `{"kind": "warp", "rect": [300, 200, 360, 280], "mode": 1, "b13": 0, "to_area": 2, "to_x": 632, "to_y": 384}`
* `pickups`, `objects`: items to find and scenery objects. `music` = the area's music track.
Area numbers match the map files (`area02.json` = `area02.tmx`); `start` is a safe position in each area to warp to.

## 9. Testing and sharing
* Play `log1_modern.gba` in mGBA.
* `make verify-mods` runs the toolkit self-test; `python3 tools/assets/demo_edits.py` (on a fresh extract) shows a text, a graphics,
  a palette, a map, a table and an area edit.
* `make patch` -> `log1_modern.bps`. Players apply it to their own ROM with any BPS patcher or
  `python3 tools/bps.py apply original.gba log1_modern.bps out.gba`.

## 10. Limits
* No editors yet for sprite sheets, the dialogue tree, music or the intro movies (see `docs/progress.md`). New areas
  can't be added (existing ones can be redrawn and rewired).
* Graphics, palettes, maps and tables keep their size.
