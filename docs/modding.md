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
| Graphics and other packed data (182 BIOS-compressed blocks) | `assets/gfx/blocks/LABEL.bin` + `LABEL.png` | `tools/assets/assets.py`, `bios.py` |

## Text
`strings.txt` lists every labelled object in `.rodata` that starts with a C string (at least 3 printable characters,
with letters). Labels exist where something points, so this covers dialogue (records `{u8 speaker, u8 id, u16, ptr}`
point at each line), the opening story, menus and names. A string that fits is written in place; a longer one rewrites
its object and moves it to the appendix at the end of the data, and every pointer to it follows.

## Compressed blocks
The game unpacks graphics with `Decompress(src, flags)` (0x08009524), which chains the BIOS decoders: Huffman (swi 0x13),
then LZ77 (swi 0x11), then run-length (swi 0x14), as selected by the flags. `tools/bfdis/lz.py` finds every word-aligned
stream that a ROM word points to and decodes the chain to find each block's stages. Extract writes the fully decoded
bytes (`.bin`) and a 4bpp tile-sheet view (`.png`, 16 tiles per row, 16 grey levels = palette indexes; real colours come
from palettes elsewhere in the ROM). On build an edited block is re-packed with the same stages by `tools/assets/bios.py`
(Huffman always with 4-bit symbols, which the BIOS accepts and which always fits its tree format) and moved to the
appendix if it grew. Verified in the emulator by `make verify-mods` (the title logo).

Caveat: a block's stages are inferred from the stream headers (0x24/0x28 Huffman, 0x10 LZ77, 0x30 RLE). If decoded data
happens to start with one of those bytes, an extra stage may be assumed; compare with the call site's flags if a
re-packed block looks wrong.

## How it fits together
Same as the sequels: `assets.py extract` writes the files and `assets/manifest.json` (SHA-1 per file); `assets.py build`
turns changed files into overrides, `tools/assets/apply.py` splices them into a copy of `data/*.s`, and the normal
build links `log1_modern.gba`. This works because every pointer in the data is a symbol (`docs/shifting.md`).

## Not covered yet
Maps, palettes, the dialogue tree structure (speaker/next fields), music and the movie codec. The data is all reachable
from the disassembly (`data/*.s`), and the code that reads it is in `ref/` and `src/`.
