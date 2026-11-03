# User guide: making mods for Dragon Ball Z: The Legacy of Goku

You can change all of the game's text and conversations, the story (quests), its graphics, palettes and character
sprites, its maps, who and what is in each area (characters, enemies, warps), enemy stats, the player's levels,
the sound samples, the music and the intro movies, build a playable ROM, and share it as a patch, without knowing assembly or C.

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

## 3. Text (`assets/text/strings.txt`; conversations are in section 9)
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

## 9. Conversations (`assets/dialogue/setNN.txt`)
Each file is one conversation set; each line is `INDEX: SPEAKER > NEXT | text`. The game shows a line (with the
speaker's face; names as in `assets/areas/SPRITES.txt`), then goes to line NEXT, until a line `INDEX: end > NEXT`; next
time that conversation starts at NEXT. So:
* change a text: edit after the `|` (`{0A}` = new line). Any length.
* add a line: give it the next free INDEX at the end of the file, and point an existing line's NEXT at it.
* change who talks: the SPEAKER name.
Which set a character uses is the `param` of the character in `assets/areas/areaNN.json`.

## 10. The story (`assets/story/quests.json`)
The game's story is 75 quests. Each has `tasks` (all must happen) and `actions` (what happens then). For example
quest 3, "Roshi's Magazines", waits for quests 0, 1 and 2 (bring Roshi his magazines) and then plays a conversation,
gives EXP, plays a scene and moves conversations on. Task types: `talk_with_item`, `defeat` (an enemy by sprite set),
`after_quest`, `after_conversation`, `spawn_item` (a pickup lying at x, y) and others. Action types: `give_exp`,
`give_pickup`, `conversation`, `set_entry` (what a character says next time), `warp`, `music`, `set_walkable` and
others. All types and fields are listed at the top of `tools/assets/quests.py`.
* Change numbers (EXP, positions, which conversation, which area).
* Remove a task or action (delete its line) or add one: copy a line of the same type, delete its `label`, change
  the values. Keep task `id`s unique (0-127).
* Characters in `areas/*.json` appear or vanish by quest: their `flag` is a position in `quest_of_flag`, whose number
  is the quest.

## 11. Character sprites (`assets/sprites/NAME.png`)
One sheet per character: 4 columns (facing directions) and 19 rows (animation frames). Edit in an indexed-colour editor
with the sheet's 16 colours (colour 0 = transparent), inside each frame's area (empty cells and the space around a
small frame are ignored). A frame that the game mirrors for the other direction is shown mirrored; edit either copy.
The colours themselves are in `assets/palettes/` (see `manifest.json` for which palette a sheet uses).

## 12. Sounds (`assets/sound/`)
`sampleNN.wav` are the 20 instrument and effect samples. Replace one with your own WAV (mono or stereo, 8 or 16 bit,
any rate and length; keep it short, the GBA has little space). `samples.json` holds loop settings: `loop` 0 = play
once, 1 or 3 = loop from `loop_start` (in samples).

**Music** (`assets/music/songNN.txt`): every song as tracker text. `tempo` and `speed` set the pace, `order` lists
the patterns in play order (the song loops back to the start), and each pattern row lists what channels do:
`CHANNEL NOTE SAMPLE VOLUME EFFECT`, for example `2 C-5 03 64 ...` = channel 2 plays C-5 with sample 3 (the WAV
numbers above) at full volume (0-64). `=` repeats the channel's last value, `..` / `...` = nothing, `===` = note off.
Effects are Impulse Tracker letters (`A06` = speed 6, `T96` = tempo 0x96, `D07` = volume slide). Change notes,
add rows or patterns, reorder. For working in a tracker program (OpenMPT, `.it` files), the
[webfootaudioengine](https://github.com/ghxstboyy/webfootaudioengine) tool converts LoG1 songs to and from `.it`
directly in a ROM: run it on your finished `log1_modern.gba` as the last step.

## 13. Movies (`assets/movies/`)
The three intro movies (movie 2 plays at boot) are standard `.fli` animations (120x80) plus one PNG per frame in
`movieN/`. Edit the frames (indexed colour, 120x80; each frame keeps its own palette; you can add or delete frames,
numbered without gaps), or replace `movieN.fli` with any 120x80 8-bit FLI/FLC file made elsewhere.



## 14. Testing and sharing
* Play `log1_modern.gba` in mGBA.
* `make verify-mods` runs the toolkit self-test; `python3 tools/assets/demo_edits.py` (on a fresh extract) shows a text, a graphics,
  a palette, a map, a table, an area, a conversation, a quest, a sprite, a sound, a music and a movie edit.
* `make patch` -> `log1_modern.bps`. Players apply it to their own ROM with any BPS patcher or
  `python3 tools/bps.py apply original.gba log1_modern.bps out.gba`.

## 15. Limits
* A few quest fields (`bN`), the 17 enemy AI values and one per-area byte table aren't understood yet (see `docs/progress.md`). New areas
  can't be added (existing ones can be redrawn and rewired).
* Graphics, palettes, maps and tables keep their size.
