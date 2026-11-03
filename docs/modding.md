# Modding toolkit: technical reference

```sh
make extract          # baserom.gba -> assets/ (git-ignored; never commit or share it)
#   ...edit files under assets/...
make modern           # -> log1_modern.gba, built from your edits
make patch            # -> log1_modern.bps (share this)
make verify-mods      # self-test
```
**The step-by-step user guide is `USER_README.md`.**

| What | Files | Tool |
|---|---|---|
| All text the game points to: dialogue, story, menus, names (977 strings) | `assets/text/strings.txt` | `tools/assets/assets.py` |
| Graphics and other packed data (182 BIOS-compressed blocks), drawn in their real colours | `assets/gfx/blocks/LABEL.bin` + `LABEL.png` | `tools/assets/assets.py`, `bios.py`, `gfxinfo.py` |
| Palettes (every one those images and the areas use) | `assets/palettes/LABEL.pal` | `assets.py` |
| The 42 area maps (3 tile layers + walkable/mask layers) | `assets/maps/areaNN.tmx` (Tiled) | `tools/assets/maps.py` |
| Enemy stats, player level table | `assets/tables/enemies.csv`, `levels.csv` | `tools/assets/tables.py` |

## Text
`strings.txt` lists every labelled object in `.rodata` that starts with a C string (at least 3 printable characters,
with letters). Labels exist where something points, so this covers dialogue (records `{u8 speaker, u8 id, u16, ptr}`
point at each line), the opening story, menus and names. A string that fits is written in place; a longer one rewrites
its object and moves it to the appendix at the end of the data, and every pointer to it follows.

## Compressed blocks
The game unpacks graphics with `Decompress(src, flags)` (0x08009524), which chains the BIOS decoders: Huffman (swi 0x13),
then LZ77 (swi 0x11), then run-length (swi 0x14), then the 16-bit (swi 0x18) or 8-bit (swi 0x16) difference filter, as
selected by the flags (bits 4 to 0). `tools/bfdis/lz.py` finds every word-aligned
stream that a ROM word points to and decodes the chain to find each block's stages. Extract writes the fully decoded
bytes (`.bin`) and an indexed PNG drawn the way the game draws the block (`tools/assets/gfxinfo.py`):

| Layout | Blocks | Picture |
|---|---|---|
| `portrait` | 67 dialogue faces (512 bytes) | 32x32, 4x4 tiles of 4 bpp, 16 colours |
| `screen8` / `bitmap8` | 21 full screens (38,400 bytes: title, logos, story pictures) | 240x160, 8 bpp tiles (30x20) or a mode 4 bitmap, 256 colours |
| `tiles8` | 90 area tile sets and extra tile blocks | 8 bpp tiles, 16 per row, the area's 256 colours |
| `tiles4` | 4 others (the font, an unused block) | 4 bpp tiles, 16 per row |

The palette comes from the image header {u32 palette, u32 data, u32 flags} that the game passes to the loader; most
images keep it right before their data, full-screen pictures are listed in tables of such triples (0x085C219C), and area
tiles use their area's palette. The PNG's colour indexes are what is stored, so draw with the PNG's own palette (an RGB
image is mapped to the nearest palette colour). To change colours, edit the palette file. On build an edited block is re-packed with the same stages by `tools/assets/bios.py`
(Huffman always with 4-bit symbols, which the BIOS accepts and which always fits its tree format; difference filters
included) and moved to the
appendix if it grew. Verified in the emulator by `make verify-mods` (the title logo).

Caveat: a block's stages are inferred from the stream headers (0x24/0x28 Huffman, 0x10 LZ77, 0x30 RLE). If decoded data
happens to start with one of those bytes, an extra stage may be assumed; compare with the call site's flags if a
re-packed block looks wrong.

## Palettes
`assets/palettes/LABEL.pal` is a JASC-PAL text file (Tiled, GIMP, Aseprite and most pixel editors read it): one "R G B"
line (0-255) per colour, 16 or 256 colours, converted to and from the GBA's 15-bit colour (5 bits per channel; bit 15
is kept). The file keeps its number of colours; it is written back in place, so every image that uses it changes.

## Maps
Format and rules are in the docstring of `tools/assets/maps.py`. In short: `gAreaTable` (0x081C7C48, pointer list at
0x081CA09C) has 42 records; an area is a grid of 30x20-tile screens on three 8 bpp BG layers, plus three 1-bit-per-tile
masks (the first is where the player can walk). Its tiles are the area tile set at slot 146 and extra tile blocks from
slot 346 (slots 0-145 hold the text font). Each `areaNN.tmx` has layers `bg3 (bottom)`, `bg2`, `bg1 (top)` (tile gid =
slot + 1, with Tiled's flip flags) and `walkable`, `mask1`, `mask2` (the red flag tile = set). Edited screens used once
are rewritten in place; screens shared with another place (14 are) and empty screens that get tiles become new objects,
and only that layer and position's pointer changes. Map sizes can't change. The area records' other fields (exits,
objects, `+0x14`/`+0x18`) are not decoded yet.

## Tables
`tools/assets/tables.py` documents the fields. `enemies.csv` is `gEnemyTable` (0x086B6094, 34 entries of 0x40 bytes,
read by the enemy constructor 0x08006D90): exp, hp, defense (subtracted in full, by half or by a quarter from each hit,
0x08007352), power and 17 unnamed AI/movement values. `levels.csv` is the player's level table (0x080114A8, 25 rows):
EXP needed, max HP, power and the ki counter. Both are written in place. The level table is checked in game by
`make verify-mods`; the enemy table only in the ROM so far (the test routes don't reach an enemy).

## How it fits together
Same as the sequels: `assets.py extract` writes the files and `assets/manifest.json` (SHA-1 per file); `assets.py build`
turns changed files into overrides, `tools/assets/apply.py` splices them into a copy of `data/*.s`, and the normal
build links `log1_modern.gba`. This works because every pointer in the data is a symbol (`docs/shifting.md`).

## Not covered yet
Area exits/objects and enemy placement, the dialogue tree structure (speaker/next fields), sprite sheets, music and the
movie codec. The data is all reachable
from the disassembly (`data/*.s`), and the code that reads it is in `ref/` and `src/`.
