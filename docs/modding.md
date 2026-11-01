# Modding toolkit: technical reference

```sh
make extract                    # baserom.gba -> assets/ (about 8,300 editable files; git-ignored, never commit them)
#   ...edit files under assets/...
make modern                     # -> log2_modern.gba, built from your edits
make patch                      # -> log2_modern.bps (share this)
make verify-mods                # self-test: identity rebuild, event round trip, demo edits checked in the emulator
```
**The step-by-step user guide is `USER_README.md`.** This file explains how the tools work.

| What | Files | Tool |
|---|---|---|
| Cutscenes, NPC talk, signs, triggers (with all dialogue) | `assets/scripts/<list>.evt` (291 event lists, 1,811 steps) | `tools/scripts/events.py`, `l2script.py` |
| UI text | `assets/text/ui_strings.txt` (260) | `tools/assets/assets.py` |
| Maps | `assets/maps/<wXX_aYY_Name>/L<k>.csv`, `tiles.txt`, `floor.png`, `area.png` | `tools/assets/mapassets.py`, `maps.py` |
| Background tiles | `assets/gfx/tiles/page_NNN.png` (168 pages) | `tools/assets/gfx.py` |
| Sprites | `assets/gfx/sprites/<animation>/*.png` (689 animations, 6,014 images) | `tools/assets/sprites.py` |
| Areas, items, enemies, enemy placement | `assets/tables/*.csv` | `tools/assets/tables.py` |
| Palette, EXP curve | `assets/palette/master.txt`, `assets/tables/exp.csv` | `tools/assets/assets.py` |
All game-specific addresses used by these tools are in `tools/assets/const.py`.

## 1. Scripts and events

### The VM
`ScriptVM_Run` (0x080092E4) runs bytecode until opcode 0x11. Opcode handlers: table 0x083B5C00 (30 entries). The instruction
set is the Buu's Fury one minus `mod`, with **one-byte jump offsets**: `jmp`/`jz` jump forward `u8` bytes counted from the
byte after the offset, `loop` jumps backward. Natives: 145 at 0x083B5D28; natives 0x00-0x10 double as variables with
setters at 0x083B5F70 (`hp`, `max_hp`, `ki`, `cur_char`...). Names: `config/script_natives.txt`; code of every native:
`docs/script_natives.md` (regenerate with `tools/scripts/natives_report.py`).

### Event lists (`.evt`)
An event list is a 0-terminated array of pointers to steps `[u16 id][u8 type][...]`. Step types (handler table 0x083EC84C):
| Type | Layout | `.evt` |
|---|---|---|
| 0 | bytecode | `step N code` + indented lines |
| 1 | `[u8 speaker]` ASCII text, 0-terminated | `step N say SPK "text"` |
| 2 | `[u8 speaker]` WFZ bitstream of the text (word aligned) | `step N zsay SPK "text"` |
| 3 | `[u8 speaker][u32 -> format text]` + bytecode computing the arguments | `step N sayf SPK LABEL` + code |
| 4 | `[u8 speaker][u32 -> argument bytecode]` + WFZ bitstream of the format text | `step N zsayf SPK LABEL "format"` |
| 5 | `[u8][u32 -> event list]` | `step N goto LABEL` |
Lists are found by scanning `.rodata` for 0-terminated pointer arrays whose targets parse as steps numbered 1, 2, 3...
`tools/scripts/roundtrip.py` checks that every one of the 1,811 steps re-encodes from its text.

How a build applies an edited list (`events.compile_list`): each step is encoded; a step identical to the original
object is kept; a changed step overwrites its object if it fits, or becomes a new object in the appendix; pointer-bearing
steps (3, 4, 5) are emitted as assembly with symbolic `.4byte` so they survive moves; if the list of objects changed,
the pointer array is rewritten (and moved if it grew). Lists numbered 1, 2, 3... are renumbered by position.

Text is ASCII (Latin-1). Box codes at the start of a line: `@^` narration, `#` portrait box, `!` alternative style;
`\x0b` = next page. Compressed text uses the same WFZ coder as the graphics (`tools/wfz`); the compressor starts each
stream with the 8-bit literal mode switch the game's decoder expects.

## 2. Maps
Same format as Buu's Fury (Webfoot engine). An area's `scene` field points at a record whose first word is map record + 4.
Map record M: `+0x18..+0x24` layer headers BG0-BG3, `+0x38/+0x3C` floor/play-area masks (WFZ, 8 KB, 1 bit per 8x8 cell),
`+0x4C` tile list (WFZ u16 deltas), `+0x50` the global page table (0x084DF574). Layer header: `+0x14` dims (chunks wide /
high), `+0x18` chunk pointers (WFZ, 32x32 u16 cells: bits 0-9 tile slot, 10 h-flip, 11 v-flip). Maps are found as every
record that points at the page table at +0x50 (336). Build rules: a changed chunk used once is recompressed in place
(or moved if it grew); a shared chunk is copied (copy-on-write).

## 3. Graphics
* Tile pages: WFZ blocks of 256 8bpp tiles, BG half of the master palette.
* Sprites: LoG2 frame records are 12 bytes `[s8 x][s8 y][u8 w][u8 h][u16 attr0][u16 attr1][u32 -> pixels]` in arrays (one
  per animation). Pixels are 8bpp, 1D tile order, OBJ palette; most are WFZ blocks, some are stored raw (both handled).
  Found by scanning for records whose OAM shape/size matches w/h and the pixel block size.
* Palette: 512 x 24-bit at 0x083ECBA4.

## 4. Tables (`assets/tables/*.csv`)
Fixed-size records; `ptr` columns hold labels so pointers stay symbolic; `_` columns are read-only hints.
| Table | Where | Notes |
|---|---|---|
| `areas` | 0x08409368, 327 x 56 | world, area, name (UI index or script), event/actor list pointers, music (number or script), scene |
| `items` | 0x086ADE24, 50 x 56 | name/desc UI indexes, max count, two icons, use handler |
| `enemies` | 0x086D56AC, 109 x 24 | exp, hp, character, str/pow/end, damage taken multipliers, AI table |
| `spawns` | 666 x 28 (records starting with 0x0800E77F) | enemy type, x, y, patrol path |
| `exp` | 0x081D9834, 50 x u32 | total EXP per level |

### Enemies
The spawn function `sub_0800E77E` creates an enemy from the spawn record: type = record+8, stats = `0x086D56AC + 24*type`.
The live enemy object keeps the stats pointer at +0x180 and its current HP at +0x188 (checked in the emulator: editing
`hp` in `enemies.csv` changes the value there). On defeat, EXP from the record is given; if it is above 5 the game
limits it to between 1/128 and 1/2 of the EXP the current character needs for its next level (`sub_0800E4D2` in
`code_0800C810`, see `ref/`).

## 5. How it fits together
* `make extract` runs `tools/assets/assets.py extract`: it scans the ROM, writes the files and `assets/manifest.json` (SHA-1 of
  every file at extraction).
* `make modern` runs `assets.py build`, which turns every file whose SHA-1 changed into **overrides**: binary blobs or assembly
  snippets with symbolic pointers, plus new objects. `tools/assets/apply.py` splices them into a copy of `data/*.s`
  (`build_modern/src`), and the normal build links the ROM. Objects that grow go to `rodata_appendix.s` at the end of
  `.rodata` under their old label, so every pointer follows. Object boundaries come from the labels in `data/*.s`
  (`tools/assets/labels.py`).
* The appendix pushes the RW image (copied to IWRAM at boot) later; that is safe because the whole data area is
  relocatable (`docs/shifting.md`). With more than 6.8 KB of growth the ROM becomes larger than 8 MB, which emulators and
  flash carts accept.
