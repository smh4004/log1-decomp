# The C layer: how the decompilation works

This repo has two kinds of "source" for the game's code:

1. **`asm/*.s`, the ground truth.** It's a matching disassembly, so `make` rebuilds the original ROM byte for byte.
2. **`src/**/*.c`, a non-matching C decompilation.** It's machine-generated, then tested function by function against the original
   machine code, and linked in place of the assembly with `make decomp`.

The C can't be byte-matching. The game was compiled with ARM ADS 1.1/1.2 `tcpp`, a proprietary compiler that isn't
redistributable (evidence in `docs/decomp_scope.md`). This C is compiled with GCC instead, so it produces different instructions
that are meant to behave the same. "Behave the same" is checked, not assumed. The rest of this document explains how,
and how far the checks can be trusted.

```
baserom.gba ──make──▶ log1.elf (matching, symbols)
                         │
        Ghidra headless  ▼   tools/ghidra/*.java
          functions.jsonl + reference C for every function     (.analysis/ghidra, from your ROM, git-ignored)
                         │
     autodecomp.py tus   ▼   one translation unit per function (types, externs, absolute addresses)
     autodecomp.py compile   arm-none-eabi-gcc -mthumb -O2, linked at a scratch address against the ROM's symbols
     autodecomp.py test      run original vs. C in Unicorn from real CPU snapshots, compare everything
     autodecomp.py emit      src/<asm file>/<function>.c + config/decomp_<tier>.txt
                         │
     make DECOMP=1/2/3   ▼   asm with those functions removed (.ifndef DECOMP_<name>) + the C objects linked in
                             -> log1_decomp.gba, then whole-game checks with the harness (tools/decomp/gamebisect.py)
```

## Tiers (current numbers)
| File | Count | Meaning | Built by |
|---|---:|---|---|
| `config/decomp_verified.txt` | 166 | Equivalent to the original on every captured snapshot (up to 30 per function, from the Kame House routes and all 41 areas, plus a run with noise on the free stack), ≥90% of its instructions executed during the tests, cleared by the per-function whole-game bisect, **and** with all 166 linked, no difference from the original on any checkpoint a pure timing change leaves intact (`wholegame.py`; see "Timing") | `make decomp` (= `DECOMP=1`) |
| `config/decomp_tested.txt` | 102 | The same, including both whole-game checks (run with verified + tested linked), but less than 90% of the function was exercised | `make DECOMP=2` |
| `config/decomp_untested.txt` | 174 | Compiles and links, but no snapshot exercised it (157 never reached, 17 only inconclusively: they never return, like `AgbMain`, or hit an unemulated BIOS call). **Unverified**: read it as Ghidra's best guess | `make DECOMP=3` (experimental) |
| `config/decomp_failing.txt` | 46 | 23 differ from the original on at least one snapshot; 23 are blocklisted | never linked; the header comment says why |
| `config/decomp_blocklist.txt` | 26 | 22 functions that passed the snapshots but changed the game in the whole-game check, 3 that can't be expressed in C or would erase data (see "What can't be replaced"), and the harness's frame-sync function `WaitForVBlank` | |
| `config/replaceable.txt` | 490 | Functions the build can swap out. 488 have C that compiles (23 of them hand-written, `tools/decomp/manual/`); the other 2 have no C equivalent | |

Every `src/*.c` file starts with a header comment that gives the original address range, its tier, and how many snapshots it passed.

**Reference C for every function** (all 865, including the ones that aren't replaceable) is in `ref/code_*.c`, one file per
`asm/code_*.s`, with `ref/index.tsv` mapping functions to files. That's the "read the whole game in C" view. It isn't compiled, and
`tools/ghidra/export.sh` regenerates it (into `.analysis/ghidra/c/`).

## Step by step

### 1. Ghidra project (one-time, about 2 minutes)
```sh
make                                                        # log1.elf has every label from the disassembly
tools/ghidra/setup.sh  $GHIDRA ~/gproj bf                   # import + analysis + fix-ups
tools/ghidra/export.sh $GHIDRA ~/gproj bf                   # -> .analysis/ghidra/{functions.jsonl, c/*.c}
```
* **Import the ELF, not the raw ROM.** Ghidra then gets all function boundaries and names from the disassembler and doesn't
  have to discover them itself. Every label is a global symbol, so auto-analysis starts about 3,000 bogus functions at
  branch targets (`_08XXXXXX`); `FixFlow.java` deletes them again.
* `AddGbaMemory.java` adds EWRAM/IWRAM/IO/palette/VRAM/OAM blocks and names the IO registers (`REG_DISPCNT`, ...).
* `FixFlow.java` runs in a second pass **without** auto-analysis, because the analyzers would undo it:
  * Ghidra decides that the armlink veneers (`bx pc; ldr pc, =target` into IWRAM) never return. It then cuts
    every caller off after the call, so a fill loop decompiled as a single call. The script clears the noreturn flags and the
    call-return overrides, models each veneer's jump as call-and-return, disassembles the cut-off code (in Thumb mode) and
    recomputes function bodies.
  * `tools/ghidra/veneer_sigs.py` counts how many argument registers each veneer target reads (`memset(dst, val, len)`
    has 3). Without a fixed signature, Ghidra guessed a different argument list at every call site and dropped arguments.
* `ApplyArgCounts.java` (third run, after `tools/ghidra/arg_counts.py`) fixes parameter lists. Ghidra infers a function's
  parameters while decompiling it but doesn't store them, so each caller was decompiled with its own guess, and arguments
  went missing (the text printer called `sub_08008DBE(obj)` instead of `sub_08008DBE(obj, ch)`; the area loader's camera
  code read a 2-byte value as one byte). `arg_counts.py` counts, for every function, which of r0-r3 the machine code
  reads before writing them: following branches and calls through the call graph, counting arguments spilled with
  `push {r0, r1, lr}` and read back from the stack, and following Thumb `bx pc` stubs into their ARM bodies (the
  divide routines). Variadic functions (`push {r0-r3}`) count only their named arguments. The script commits Ghidra's
  parameters for every function and sets each list to the machine-code count (widened, or trimmed where Ghidra assumed
  a call through a register passes r1-r3 along; never below a function with stack arguments).
  ```sh
  python3 tools/ghidra/arg_counts.py
  $GHIDRA/support/analyzeHeadless ~/gproj log1 -process -noanalysis -scriptPath tools/ghidra \
      -postScript ApplyArgCounts.java $PWD/.analysis/ghidra/arg_counts.txt
  ```
* `ExportFunctions.java` writes one JSON line per function:
  `{name, addr, c, sig, globals:[[name,type,addr,size]], callees:[[name,proto,addr]]}`. `ExportDecomp.java` writes the
  reference C, one file per `asm/code_*.s`.

### 2. Translation units (`autodecomp.py tus`)
For each replaceable function, the Ghidra C is wrapped with `include/ghidra_types.h` (Ghidra's `undefined4`, `CONCAT`,
`SUB`, `CARRY4`... spelled as C macros) plus `extern` declarations for its callees and globals. Every global gets an
absolute address in a per-function linker script, so `DAT_03001c34` is a real symbol at 0x03001C34.
Ghidra notations that aren't C are translated: `x._2_2_` (2 bytes at offset 2 of x) becomes a pointer access;
raw addresses Ghidra never exported as globals (`Ram040000dc`, `_DAT_030005f0`, `sRam0300086e`) become absolute
accesses, sized by Ghidra's prefix or, when it has none, by the instruction that accesses them (`ldrh`, `ldrsb`...;
the same is done for globals Ghidra left untyped, which it otherwise declares as one byte); ROM data is referred to
through the label that contains it (`gUnknown_080116C0 + 0x4`), not a number; a callee whose result Ghidra keeps
in an `undefined8` (quotient and remainder of `__rt_sdiv` in r0:r1) is declared as returning 64 bits.

**Hand-written C** in `tools/decomp/manual/NAME.c` replaces Ghidra's text for 23 functions it can't express: BIOS
calls (`Decompress`, `Div`, `SoftReset`, semihosting), the variadic text formatter, a divide's remainder used from r1,
and GCC-compiled library code whose `pop {r1}; bx r1` returns Ghidra took for jump tables. See
`tools/decomp/manual/README.md`. They go through the same compile and tests as everything else.

A function is **rejected** if Ghidra's output contains:
* `unaff_*`, `in_r*`, `extraout_*`: Ghidra couldn't work out the calling convention (callee-saved registers used as inputs, or results in odd registers).
* `halt_baddata`, `UNRECOVERED_JUMPTABLE`, `switchD_*`, `software_interrupt`, `coprocessor`: things it couldn't express in C.
* 64-bit types or doubles where the ABI can't be checked, or ROM-absolute data addresses (`DAT_08...`) that wouldn't follow a relocation.

### 3. Compile (`autodecomp.py compile`)
`arm-none-eabi-gcc -mthumb -mcpu=arm7tdmi -O2 -fwrapv -fno-strict-aliasing -fno-delete-null-pointer-checks ...`
through `tools/decomp/cc.sh`. Modern GCC always returns through `pop {rN}; bx rN` on ARMv4T, and in a `void` function rN is
r0, which destroys a value the original left in r0 for its caller. The wrapper rewrites that epilogue to `pop {pc}`,
which is how ADS returns too. The Makefile uses the same wrapper.
`-fwrapv` and no strict aliasing make GCC treat Ghidra's pointer casts and overflow arithmetic the way the hardware does.
The object is linked at 0x09000000 against `--just-symbols=log1.elf`, so calls go to the **original** functions.
The candidate's own symbol is renamed to `__candidate` first. Without that, the ROM's symbol of the same name would win and
the test would end up comparing the original with itself. (This bug happened once. Every function was recompiled and retested after it was fixed.)

### 4. Snapshots (`tools/harness/harness`)
The headless mGBA harness plays scripted input routes (`tools/harness/*.txt`). `capture LIST DIR N` stops whenever the next instruction is the entry of a
listed function and saves the registers (r0–r15, CPSR) and all of RAM, IO, palette, VRAM and OAM, up to N times per function.
Snapshot format: 18 u32 registers, then per region `base, size, zlen` and zlib data.
The capture routes `smoke`, `long` and `explore1-3` (generated by `tools/harness/make_explore.py`) only play around
Kame House. `tools/harness/capture_variants.py` reaches the rest of the game: for each of the other 41 areas it makes a
*capture-only* ROM in which one data record changes (Kame House's exit warp is widened to the whole island and
pointed at that area's start; no code changes), plays the intro, walks into the warp and explores the area at random.
`STRONG=1` makes a second set with a strong level-1 Goku (its row in the level table), so fights are won rather than
lost. Together the routes reach 332 of the 490 replaceable functions (56,151 snapshots, up to 3 per function
per route). `.analysis/snaps/roms.json` records which ROM each route's snapshots came from, and the tester runs them
against that ROM's data. Per function, the tester uses at most 30 snapshots (`MAXSNAP`), taken round-robin across
routes. Snapshots are made from your ROM's
memory, so they live in `.analysis/snaps` and are never committed.

> mGBA detail: while stepping, `gprs[15]` is one Thumb instruction ahead, so the next instruction is at `pc - 2`.
> The first version captured one instruction late. That's the kind of off-by-one that makes every test "pass" for the wrong reason.

### 5. Equivalence test (`autodecomp.py test`)
For each snapshot, run the **original** code from the ROM and then the **candidate** from the same state in Unicorn
(ARM926 in ARMv4T mode, with the GBA memory map). Each run ends when the function returns to a magic LR. Then compare:
* r0, **even when Ghidra says the function is `void`**. ADS C++ constructors return `this`, and factories return their callee's result.
  Ghidra types both as `void`, and callers use the value. When the original returns its first argument, `autodecomp.py fixthis`
  rewrites the C to `return param_1;` and the function is tested again. A difference in r0 is tolerated only for functions that
  `tools/decomp/r0live.py` proves nobody reads r0 from (every direct caller overwrites r0 before reading it, the address
  is never taken, and it's never tail-called),
  `r0live.py` follows a value that a caller returns unchanged up to that caller's callers. A weaker rule accepts the
  rest (`equal-r0unread`): no *direct* caller reads r0, **and** the caller this snapshot returns to (its LR) doesn't
  either. Calls through pointers that no snapshot saw aren't covered by it. `autodecomp.py fixvoid` first tries to
  reproduce such a value (the last callee's result, or the first argument),
* r4–r11 and SP (callee-saved, so they must be restored),
* every byte of EWRAM, IWRAM, IO, palette, VRAM and OAM, **except** the stack below the entry SP (scratch space that differs because GCC lays out frames differently).

Calls out of the function run the original code in both runs, so a candidate is judged only on its own behaviour.
BIOS calls are emulated at a high level, the same way in both runs: the decompressors (LZ77, Huffman, run-length,
Diff8/16) with the decoders from `tools/bfdis/lz.py`, `Div`, and the `Halt` in `WaitForVBlank`, modelled as the VBlank
interrupt having set the flag it waits for (so a function that waits a few frames runs to completion). Other BIOS
calls and faults make the snapshot **inconclusive**. A function is **accepted** only if no snapshot differs and at least one is equal.
The tester also records **coverage**: the fraction of the original's instructions executed across all its snapshots.

### 6. Is the tester actually strict? (`tools/decomp/mutation_check.py`)
Take accepted, fully covered functions, inject one mutation into the C (`+ 1` -> `+ 2`, `<` -> `<=`, `= 0;` -> `= 3;`, ...) and test
again. Latest run (with the snapshots from all 41 areas): **17 of 25 mutants caught**. When the survivors of an earlier
run (19 of 25) were examined one by one, they were of two kinds:
* mutated a value that's dead (a return value no caller reads, or a register write overwritten later in the function, as in `REG_DISPCNT = 0` followed by `= 0x200`), so the mutant really is equivalent;
* or changed a branch condition at a boundary no snapshot hits (`<` -> `<=`).
The second kind is the real gap. More capture routes close it, and the whole-game check (step 7) catches what it can.

### 7. Whole-game check (`tools/decomp/gamebisect.py`, `tools/harness/decomp_route.txt`)
Passing every snapshot doesn't prove a function is correct for inputs the snapshots never had. So the verified tier is also linked
**together** and played through a route, and every screenshot checkpoint must match the matching ROM.

**Time must be counted in game loops, not video frames.** Any change in code speed shifts the game's lag frames. Even a
16-byte jump into an *identical copy* of a function moved the boot sequence by 38 video frames, so a scripted START
press arrived on a different screen. The harness command `syncpc 0x080099F2` makes every `run`/`tap` step one pass of the
game's main loop past its VBlank wait (`WaitForVBlank`, 0x080099B6), so inputs reach the same game state however fast the code
runs. In that mode, a ROM with a relocated function matches the original on all checkpoints, so any remaining difference comes from the
C code. `decomp_route.txt` is `smoke.txt` in that mode. (`WaitForVBlank` itself is in `config/decomp_blocklist.txt`, since the sync
address must stay in place.)

If a checkpoint differs, `gamebisect.py LIST ROUTE [JOBS]` builds ROMs from halves of the list (in parallel build directories,
`make DECOMP_DIR=...`) until it isolates the culprits. They go into `config/decomp_blocklist.txt` with a reason, and `emit`
moves them to `decomp_failing.txt`.

What the whole-game check caught, and what was changed in the pipeline because of it:
| Symptom | Cause | Fix |
|---|---|---|
| Constructors returned garbage | Ghidra types ADS constructors (which return `this`) as `void` | r0 compared even for `void`; `fixthis` |
| Factory functions broke callers | `void` functions whose r0 is their callee's result: GCC's `pop {r0}; bx r0` epilogue destroyed it | `cc.sh` rewrites the epilogue to `pop {pc}` (like ADS); r0 strict unless `r0live.py` proves it dead |
| A fill loop ran once | Ghidra's noreturn analysis marked armlink veneers as non-returning and cut the caller after the call | `tools/ghidra/FixFlow.java` (see step 1) |
| A screen-clear lost its arguments | Ghidra guessed per-call argument lists for veneers into IWRAM | `veneer_sigs.py` + fixed signatures |
| r3 clobbered | `-mlong-calls` loads call targets into r3, but ADS functions pass r1-r3 straight through | no long calls; linker veneers use only `ip` |
| A rectangle passed by pointer lost 3 of 4 fields | Ghidra splits a stack struct into separate locals (`uStack_20`, `uStack_1c`...), and GCC drops stores to the ones it thinks nobody reads | `stack_frame()`: when a stack slot's address escapes, all slots become one frame array at their original offsets |
| Text formatter lost arguments | Variadic functions (`push {r0-r3}` prologue) walk the caller's stack; Ghidra copies only the named registers | variadic functions are not replaced |
| A sound sequencer never saw its end marker | Ghidra writes `*(char *)p == -1`, so it assumes signed `char`, but GCC's ARM `char` is unsigned | `-fsigned-char` |
| Everything after the C code moved | C code was originally linked before .rodata, and replaced functions were padded only to alignment | C goes after all original data; full-size padding |

### Timing: what the whole-game check can and can't judge
`syncpc` keeps the routes' inputs in step with the game loop, but not everything follows the game loop. The interrupt
handler runs once per video frame (sound, fades, and state the game logic reads), so when a loop pass runs over a
frame, that state drifts, and from some point on the game takes a different turn. This happens to the original
code too. Control experiment: `sub_0800EC80` replaced by **an exact copy of its own instructions**, linked like
the C (long jump, body in `.decomp`). That ROM's only difference is a few cycles at boot, yet `decomp_explore.txt`
differs from checkpoint 9 on. With all verified functions linked, the C runs slower and drifts much earlier: the
timing control for that set (`tools/decomp/timing_control.py`: every listed function replaced by a relocated copy
of its original instructions) already differs from the original on 205 of 492 area checkpoints, exactly as many
as the C build.

So the whole-game check compares the C with the original only where a pure timing change of the same size leaves the
game unchanged:
* **Per function** (`gamebisect.py` with `HORIZON=build/horizon.json`): builds with small subsets barely change the
  timing. `tools/decomp/timing_horizon.py` measures each route's horizon with two one-function controls
  (`tools/decomp/timing/`): 22 of 22 checkpoints on `decomp_route`, 36 of 37 on `decomp_long`, 9 of 14 on
  `decomp_explore`, and all 492 in the 41 areas (`decomp_warp.txt`, played with `WARPS=1,...,41`: the same one-record
  warp patch as the capture ROMs, applied to both ROMs). The bisect then finds the functions whose build differs before
  the horizon. They're blocklisted, conservatively: a C function much slower than the original could cross the horizon
  through timing alone.
* **The whole tier together** (`tools/decomp/wholegame.py LIST`): the C build, its timing control and the original
  play every route, and the C is compared with the original up to the first checkpoint where the control differs, in
  each run.

## How C replaces assembly in the build
Each replaceable function in `asm/code_*.s` is wrapped like this:
```asm
	.ifndef DECOMP_sub_08009744
	thumb_func_start sub_08009744      @ the original instructions (matching build)
	...
	.else
	thumb_func_start sub_08009744      @ decomp build: same address, now a long jump
	bx pc
	nop
	.arm
	ldr ip, [pc]
	bx ip
	.4byte sub_08009744__c + 1         @ the GCC-compiled C, renamed by the Makefile
	.thumb
	.space 40                          @ pad to the original size
	.endif
```
The C objects are linked in a `.decomp` section in the free space after the end of the data (0x087A6418 onward, inside the 8 MB padding). This has three effects:
* **No original byte moves.** All data, every other function and every literal pool keep their addresses, so a
  difference in game behaviour can only come from the C code itself.
* Every way of reaching the function still works: `bl`, tail-call `b`/`bcc`, vtable entries, function pointers in data.
* Calls from the C back into the code area are more than 4 MB away (out of `bl` range). GNU ld inserts long-branch veneers
  for them in the `.decomp` section, and those veneers only use `ip`. Don't compile with `-mlong-calls`. GCC would then load the target
  into a low register (r3), and some ADS functions pass r1-r3 straight through to their callees without Ghidra noticing.

## What can't be replaced, and why
A function stays assembly-only (and isn't in `replaceable.txt`) when:
* **It's smaller than the jump** (16 bytes, or 18 if it starts on a halfword boundary). These are mostly one-line getters and setters. Their
  reference C is still in `.analysis/ghidra/c/`.
* **Another function jumps into its middle**: an inner label is referenced from outside, as with shared epilogues and ADS tail merges.
* **It's ARM code, a veneer, a C++ MI thunk, or part of the runtime library** (`__rt_sdiv`, `__call_via_rN`, ...).

Three replaceable functions stay assembly for structural reasons (`config/decomp_blocklist.txt`): `sub_08000520` is
entered by a branch from inside another function and returns through that function's stack frame; `sub_0800E8A0`'s body
continues in code that uses its frame; and `sub_0800EE44`'s range in the disassembly also holds the static-constructor
table that `sub_0800E4B0` walks at startup, which replacing it would erase.

## How to work on a function
1. Find it: `grep -rl sub_08009744 src/ asm/`, or by address in `.analysis/ghidra/c/index.tsv`.
2. Edit `src/<file>/<func>.c`: rename variables, add structs. Names go in `config/symbols.txt` (then rerun `gen.py`) so
   asm and C agree.
3. Test that one function against its snapshots:
   `python3 tools/decomp/autodecomp.py test --only sub_08009744` (or the whole set without `--only`).
4. `make DECOMP=1` (or put it in your own list: `make DECOMP=1 DECOMP_LIST=mylist.txt`) and play it:
   `tools/harness/harness log1_decomp.gba tools/harness/decomp_long.txt outdir`.
5. To promote a function to a better tier, more snapshots must reach it. Add a route that exercises it and capture with `harness ... capture`.

## Honest limits
* **Untested ≠ wrong, but also ≠ right.** 174 replaceable functions (36%) have no conclusive snapshot: story events
  that depend on quest progress, the save chip, the ending, error paths. Their C is Ghidra's reading of the machine code
  (with the argument counts checked against it), with no execution evidence behind it.
* **The whole-game check is limited by timing.** The game itself plays differently once its speed changes (see
  "Timing"), so with a whole tier linked only 174 of 565 checkpoints can judge the C. The per-function bisect, where the
  timing barely changes, uses nearly all of them.
* **`equal-r0unread` is weaker than a proof.** It covers the direct callers and the return sites the snapshots saw, not
  calls through pointers that no route reached.
* Ghidra output is readable but not idiomatic: `param_1`, `iVar3`, pointer arithmetic instead of structs, C++ `this`
  as a plain `int`. Classes aren't recovered (the vtables are labelled in asm, and their methods are the
  `sub_` functions they point to).
* The decomp build's ROM isn't the original ROM. The matching build (`make compare`) is what proves the repo is complete.
