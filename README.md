# Dragon Ball Z: The Legacy of Goku (USA): disassembly and decompilation

A pret-style source tree for **Dragon Ball Z: The Legacy of Goku (USA)** (GBA, `ALGE`, Webfoot 2002). It provides:

* **A matching disassembly.** `make` rebuilds the original 8 MB ROM byte for byte from labelled assembly and data.
* **Shiftable source.** Every pointer is a symbol, so code and data can grow, shrink and move. This is tested by
  inserting padding before everything and playing the game through an automated route (37/37 checkpoints identical).
* **Modding toolkit** (`USER_README.md`, `docs/modding.md`): the story (75 quests: tasks, rewards, what happens next)
  and all 80 conversations (speaker, next line, text) as editable files; every other string the game points to as one text file; all 182 BIOS-compressed graphics blocks as PNGs in their real layout and colours
  (faces, full screens, area tile sets), re-packed with Huffman / LZ77 / run-length / diff encoders on build; every
  palette as a JASC-PAL file; the 42 area maps as Tiled `.tmx` files (3 tile layers plus the walkable mask); what is
  in each area (characters, enemies, pickups, warps and other trigger zones) as JSON; enemy stats and the player's
  level table as CSV. Text can grow.
* **A C decompilation.** Ghidra reference C for all 865 functions (`ref/`), and **58 functions run as GCC-compiled C** in
  `make decomp`, a ROM that plays all three test routes identically to the original. Each was checked for equivalence
  against the original machine code first. Another 47 pass their tests but aren't whole-game clean yet, and 190 compile
  but haven't been reached by a test.
* **Tooling.** A headless mGBA harness (screenshots, breakpoints, memory watches, PC traces, call logs, CPU snapshots)
  and a Unicorn equivalence tester.

> **No ROM data is included.** Everything copyrighted is read at build time from your own `baserom.gba`
> (SHA-1 `a3c8c76742f11fc6a3f6e3fcca20992458cac0b5`, the stand-alone USA cartridge). Share hacks as `.bps` patches.

Sister projects: [log2-decomp](https://github.com/smh4004/log2-decomp) (Legacy of Goku II) and
[buusfury-decomp](https://github.com/smh4004/buusfury-decomp) (Buu's Fury). The tools are shared; everything
game-specific is in `config/game.json` and `tools/assets/const.py`. This game is the oldest of the three: an older
ARM compiler (`docs/toolchain.md`), no WFZ compression (it uses the GBA BIOS coders), and a small code base (64 KB).

## Quick start
```sh
sudo apt-get install gcc-arm-none-eabi binutils-arm-none-eabi make python3 python3-pip libmgba-dev libpng-dev zlib1g-dev
pip install --break-system-packages capstone numpy pillow unicorn
cp /path/to/your/dump.gba baserom.gba
make && make compare          # -> log1.gba: OK
make decomp                   # -> log1_decomp.gba (verified C linked in)
make extract && make modern   # modding (see USER_README.md)
```

## Builds
| Command | Output | Use it to |
|---|---|---|
| `make` / `make compare` | `log1.gba` + SHA-1 check | prove the source is complete |
| `make shift-test` | `log1_shift.gba` | prove nothing depends on absolute addresses |
| `make decomp` (`DECOMP=1/2/3`) | `log1_decomp.gba` | run C in place of assembly (2 and 3 are experimental) |
| `make extract` / `modern` / `patch` / `verify-mods` | `assets/`, `log1_modern.gba`, `.bps` | mod the game |

## Repository tour
| Path | What |
|---|---|
| `asm/`, `data/` | the disassembly (code; data with symbolic pointers and `.incbin` of the rest) |
| `src/`, `ref/` | decompiled C (tested) and Ghidra reference C for every function |
| `config/` | `game.json` (layout and per-game switches), `symbols.txt`, `regions.yaml`, decomp tiers |
| `tools/bfdis/` | disassembler (`analyze`, `emit`, `gen`, `ptrs` pointer classifier, `lz` BIOS stream finder) |
| `tools/assets/` | modding toolkit (`assets.py`, `bios.py` encoders, `gfxinfo.py`, `maps.py`, `tables.py`, `areas.py`, `dialogue.py`, `quests.py`, `apply.py`) |
| `tools/decomp/`, `tools/ghidra/` | decompilation pipeline |
| `tools/harness/` | emulator harness, routes, `shiftdiff.py`, `ramdiff.py` |
| `docs/` | `rom_map.md`, `shifting.md`, `decomp.md`, `modding.md`, `toolchain.md`, `progress.md` |

## How it was made
1. **Layout** (`docs/rom_map.md`): crt0, 59 KB of Thumb code with the ARM C library, ctor vector, veneers and vtables, 3 KB
   more code, 7.6 MB of data. No RW image (the game copies its IWRAM routines itself).
2. **Code discovery and matching assembly**: the shared disassembler found 864 functions; `make compare` matched on the
   first build.
3. **Relocation**: 9,432 pointers made symbolic. This game needed new rules (BIOS stream detection, movie and palette
   data, method tables, pointer arrays, inline pointers); each came from tracing one shift-test difference back to one ROM
   word (`docs/shifting.md`).
4. **Decompilation**: Ghidra headless on the ELF, `autodecomp.py` (translation units, GCC, Unicorn equivalence on 2,868
   snapshots), whole-game routes in game-loop time (`syncpc 0x080099F2`), `gamebisect.py` (7 culprits blocklisted).
5. **Modding**: text from labels; BIOS Huffman/LZ77/RLE/diff decoders and encoders for the graphics; image headers
   {palette, data, flags} for layout and colour; the area table for maps; the enemy constructor for enemy stats.

## Verifying
`make compare`, `make shift-test`, `python3 tools/decomp/autodecomp.py test`, the `decomp_*.txt` routes on
`log1.gba` vs `log1_decomp.gba`, and `make verify-mods`.

## Known limits
* The C is GCC, not the original compiler: behaviourally tested, not byte-matching.
* Sprite sheets, music and the movie codec have no editors yet (`docs/progress.md`).
