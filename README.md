# Dragon Ball Z: The Legacy of Goku II (USA): disassembly and decompilation

A pret-style source tree for **Dragon Ball Z: The Legacy of Goku II (USA)** (GBA, `ALFE`, Webfoot 2003). It provides:

* **A matching disassembly.** `make` rebuilds the original 8 MB ROM byte for byte from labelled assembly and data.
* **Shiftable source.** Every pointer is a symbol, so code and data can grow, shrink and move. This is tested by
  inserting padding before everything and playing the game through an automated route (37/37 checkpoints identical).
* **Modding toolkit** (`USER_README.md`, `docs/modding.md`). `make extract` turns the game into about 8,300 editable files,
  and `make modern` builds them back:
  * **events**: a decompiler and compiler for all 291 event lists (1,811 steps: cutscenes, NPC talk, signs) with their
    dialogue inline. Steps can be added and removed; text can be any length.
  * **all 336 maps**: layers as CSV grids, tile lists, collision masks.
  * **graphics**: 168 tile pages and 6,014 sprite images as PNG.
  * **text**: UI strings; dialogue is in the events.
  * **tables**: palette, EXP curve, areas, items, enemy stats (109 types) and enemy placement (666 spawns), as CSV.
  * a WFZ compressor, so any of it can grow.
* **A C decompilation.** Ghidra reference C for all 2,424 functions (`ref/`), and **267 functions run as GCC-compiled C** in a
  `make DECOMP=2` ROM that plays the test routes identically to the original: 177 verified with ≥90% coverage, plus 90
  tested with lower coverage. Each was checked for equivalence against the original machine code. Another 831 compile and
  link but haven't been verified.
* **Tooling.** A headless mGBA test harness (screenshots, breakpoints, memory watches, PC traces, CPU snapshots), and a
  Unicorn equivalence tester.

> **Want to make a mod? Start with [`USER_README.md`](USER_README.md).**

> **No ROM data is included.** Everything copyrighted is read at build time from your own `baserom.gba`
> (SHA-1 `18e0715dec419f3501c301511530d2edcd590f8b`, the stand-alone USA cartridge). Share hacks as `.bps` patches, never as
> ROMs or extracted assets.

This is the sister project of [buusfury-decomp](https://github.com/smh4004/buusfury-decomp): same Webfoot engine (an older
version), same toolchain (ARM ADS 1.x C++), same tools. Everything game-specific is in `config/game.json` and
`tools/assets/const.py`.

---

## Contents
1. [Quick start](#quick-start)
2. [What each build is for](#builds)
3. [Repository tour](#tour)
4. [How it was made](#process)
5. [Tutorials](#tutorials)
6. [Verifying anything yourself](#verify)
7. [Known limits](#limits)

---

<a name="quick-start"></a>
## 1. Quick start
```sh
# Debian/Ubuntu
sudo apt-get install gcc-arm-none-eabi binutils-arm-none-eabi make python3 python3-pip libmgba-dev libpng-dev zlib1g-dev
pip install --break-system-packages capstone numpy pillow unicorn

cp /path/to/your/dump.gba baserom.gba     # the USA ROM, SHA-1 above
make && make compare                     # -> log2.gba: OK
make decomp                              # -> log2_decomp.gba (verified C functions linked in)
```
Ghidra (11.x, Java 21) is only needed to **regenerate** the C (section 4.6).

<a name="builds"></a>
## 2. What each build is for
| Command | Output | Use it to |
|---|---|---|
| `make` / `make compare` | `log2.gba` + SHA-1 check | Prove the source is complete |
| `make SHIFT=0x100` / `make shift-test` | `log2_shift.gba` | Prove nothing depends on absolute addresses (everything after crt0 moves) |
| `make decomp` (`DECOMP=1/2/3`) | `log2_decomp.gba` | Play the game with C functions in place of assembly (1 = verified, 2 = + tested, 3 = + untested, experimental) |
| `make extract` / `make modern` / `make patch` | `assets/`, `log2_modern.gba`, `.bps` | Mod the game |
| `make verify-mods` | | Self-test of the modding toolkit |

<a name="tour"></a>
## 3. Repository tour
| Path | What |
|---|---|
| `asm/` | code: `crt0.s`, `code_*.s` (Thumb/ARM, one file per ~8 KB), `iwram.s` (RW image run from IWRAM), `macros.inc` |
| `data/` | `.rodata`: labels, symbolic pointers (`.4byte gUnknown_...`), `.incbin` of the rest from `baserom.gba` |
| `src/` | decompiled C, one file per function (only the tested tiers are linked) |
| `ref/` | Ghidra reference C for every function (read-only) |
| `config/` | `game.json` (layout), `symbols.txt` (names), `script_natives.txt`, `regions.yaml` (byte map), decomp tier lists |
| `tools/bfdis/` | the disassembler: `analyze.py` (code discovery), `emit.py`/`gen.py` (assembly), `ptrs.py` (pointers), `regions.py` |
| `tools/wfz/` | WFZ decoder, compressor, scanner |
| `tools/assets/`, `tools/scripts/` | modding toolkit |
| `tools/decomp/`, `tools/ghidra/` | decompilation pipeline |
| `tools/harness/` | headless emulator harness and routes |
| `docs/` | `rom_map.md`, `shifting.md`, `decomp.md`, `modding.md`, `script_natives.md`, `progress.md` |

<a name="process"></a>
## 4. How it was made
The tools were first written for Buu's Fury and then parameterized; this section summarises each step for LoG2.

### 4.1 Toolchain
Same as Buu's Fury: ARM ADS 1.x C++ (`__call_via_rN` stubs at 0x08021D28, `push {r3,lr}` alignment, base-relative vtables,
entry-relative `C$$pi_ctorvec`, armlink veneers into IWRAM, ADS switch tables). Assert strings name the sources
(`K:\Source\AreaEntry.cpp`, `K:\Source\ByteCodeInterpreter\...`). The C can't be recompiled to matching bytes (ADS isn't
redistributable), so the matching layer is assembly.

### 4.2 Map every byte (`docs/rom_map.md`)
Header, crt0, code (0x158-0x28724, including ctor vector, veneers and vtables), `.rodata` up to 0x7FD6BC, the RW image
(0xE7F bytes copied to IWRAM), padding. `tools/bfdis/regions.py` classifies all 8 MB.

### 4.3 Find the code (`tools/bfdis/analyze.py`)
Recursive descent from the entry point, constructors and vtables, then odd pointers, prologues and gaps, with confidence
levels so a bad guess can be rolled back. Assert strings inside code gaps are recognised as data. 2,423 functions.

### 4.4 Emit matching assembly (`gen.py`)
Every instruction as source, literal pools as `.4byte label`, switch tables as label differences, vtables as
`func - base`. One instruction needed a hand-kept raw encoding (`config/raw_insns.txt`). `make compare` matches.

### 4.5 Make data symbolic (`tools/bfdis/ptrs.py`, `docs/shifting.md`)
52,000 pointers in `.rodata` converted to labels with evidence rules; PCM audio, fonts and byte tables are recognised as
non-pointer data. Verified by the shift test.

### 4.6 Decompile (`docs/decomp.md`)
Ghidra headless imports the ELF (all labels), fixes flow around veneers, exports C. `tools/decomp/autodecomp.py` turns each
replaceable function into a translation unit, compiles it with GCC, and tests it against the original in Unicorn from
real CPU snapshots captured on five routes (5,151 snapshots of 515 functions). Accepted functions are linked in place of
the assembly by a 16-byte long jump, so no other byte moves; whole-game routes in game-loop time (`syncpc 0x08020D78`)
catch the rest (`tools/decomp/gamebisect.py` found 5 more culprits, now in `config/decomp_blocklist.txt`).

### 4.7 Assets and modding tools (`docs/modding.md`)
Maps, tile pages, palette and WFZ are the same formats as Buu's Fury; the sprite record (12 bytes), event steps (ASCII text,
compressed text, one-byte jumps) and every table were reverse-engineered for LoG2. 125 of 145 script natives are named.

<a name="tutorials"></a>
## 5. Tutorials
**Name a function or object:** add `ADDRESS Name  # comment` to `config/symbols.txt`, run `python3 tools/bfdis/gen.py
baserom.gba`, then `make compare`.

**Change code in assembly:** edit `asm/code_*.s` and build with `make SHIFT=0` (non-matching is fine once you change
behaviour). Everything is relocatable, so instructions can be added.

**Mod the game:** `USER_README.md`.

**Write new code in C:** add a `.c` file under `src/`, declare the original functions you call as `extern`, and point a
pointer or a `bl` at it; the decomp build links C after the RW image.

**Improve a decompiled function:** edit `src/<file>/<func>.c`, then `python3 tools/decomp/autodecomp.py test --only NAME`
and `make decomp`.

**Debug with the harness:** `tools/harness/harness ROM script outdir`; commands (`run`, `tap`, `shot`, `dump`, `bp`,
`mem`, `watch`, `watchon`, `tracepc`, `guard`, `capture`, `syncpc`) are listed at the top of `tools/harness/harness.c`.

<a name="verify"></a>
## 6. Verifying anything yourself
| Claim | Command |
|---|---|
| matching | `make compare` |
| relocatable | `make shift-test` (and `tools/harness/shift_test.sh 0x2000`) |
| C equivalence | `python3 tools/decomp/autodecomp.py test` (needs snapshots: harness `capture`, see `docs/decomp.md`) |
| decomp ROM plays identically | compare `shot` hashes of `tools/harness/decomp_*.txt` on `log2.gba` and `log2_decomp.gba` |
| modding toolkit | `make verify-mods` |

<a name="limits"></a>
## 7. Known limits
* The C is GCC, not ADS: behaviourally tested, not byte-matching. Untested C is Ghidra's reading, not verified.
* Capture routes cover the opening areas; functions used only later in the game stay untested until routes reach them.
* 20 script natives are unnamed and about 25 names are marked "(guess)".
* Enemy spawn records can be edited but not added; 16-colour and multi-part sprites aren't exported yet.
* Field meanings marked "(inferred)" in the table notes come from values and code reading, not from source.
