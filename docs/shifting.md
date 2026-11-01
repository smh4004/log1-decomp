# Shiftability: making every pointer symbolic

A matching disassembly can still hide absolute addresses: a data word that is really a pointer but was left as a
number keeps pointing at the old place when something moves. `make shift-test` finds those. It builds
`log2_shift.gba` with `SHIFT` bytes of padding right after crt0 (`asm/shift.s`), so **every** byte of code and data
moves, plays `tools/harness/long.txt` (title, intro, cutscenes, walking, the status menu, 60 random walks) on both
ROMs and compares a frame hash at every checkpoint.

Current result: **37 of 37 checkpoints identical** with `SHIFT=0x100` and `SHIFT=0x2000`.

## How pointers are classified (`tools/bfdis/ptrs.py`)
Every 4-byte-aligned word in uncompressed `.rodata` whose value lies inside the ROM image is a pointer candidate.
It's converted to a symbol only with evidence:

| Kind | Evidence |
|---|---|
| `wfz` | target is the first byte of a WFZ container |
| `func` | odd value at a known Thumb function, or at a Thumb instruction when the word sits in a pointer run / is referenced twice |
| `code` | the same target is also loaded by code from a literal pool |
| `label` | target is a code-area label (pool, vtable, data label) |
| `table` | target in `.rodata`, with another candidate within 8 bytes, or in a regular-stride array, or referenced 2+ times (isolated words additionally need an aligned target that is close by or referenced 3+ times) |
| `struct` | an isolated word at the start of an object something else points to |

Rejected candidates are listed with a reason in `config/ptr_ambiguous.txt` and stay numbers.

## What went wrong in Legacy of Goku II, and the rule that fixed it
Each of these was found by tracing a difference in the shift test back to one ROM word (harness `watchon` on the RAM
that differed, then comparing the bytes the code read in both ROMs):

| Symptom in the shifted ROM | Cause | Fix |
|---|---|---|
| Status menu hung in a blit loop | a sine-like byte table contained `08 09 09 08`, read as pointer 0x08090908 and shifted | `bytepattern`: words whose four bytes are all within 8 of each other need strong evidence |
| Wrong music samples / HUD pixels | 8-bit PCM samples are full of words like `0x0804F5FA` | `pcm`: a word whose 96-byte neighbourhood looks like audio (small byte-to-byte steps, few 00/FF bytes) is never a pointer; the music sample bank is listed in `config/game.json` `noptr` |
| One pixel of the HUD and of the menu font | font glyph rows `0x0840, 0x0840` form the word 0x08400840 | the two fonts are listed in `noptr` |
| Wrong timer callback | a pool word `0x08021924` is an **even** pointer to a Thumb function; `ld` sets bit 0 on function symbols | the emitter adds a plain alias label `sub_08021924_even` |
| A table pointer in IWRAM stayed old | the RW image (copied to IWRAM) holds a pointer into `.rodata` | `emit.py data_ptr` converts aligned `.rodata` pointers inside the RW image |
| Spurious functions in strings | isolated odd words in data pointed into assert messages (`K:\Source\...`) | odd-pointer and gap stages skip printable C strings |

## Known non-pointer dependencies
* RAM values that happen to look like ROM addresses (sound mixer positions, sprite byte buffers) show up in
  `tools/harness/ramdiff.py` output as "stale"; they are not pointers.
* Fixed-layout data reached as `symbol + constant` from code is listed in `config/pinned.txt`; the asset tools keep
  those objects at their size.

## Tools
* `tools/harness/ramdiff.py A B SHIFT`: compare two RAM dumps (`dump` command) word by word; words equal to the
  original +SHIFT are "moved-ok", equal ROM-range values are "stale" (candidates for an unconverted pointer).
* harness `watchon ADDR`: every write to a word, with PC and registers; run it on both ROMs and compare.
* harness `tracepc ADDR`: registers (and 4 words at r0-r3) every time the CPU passes ADDR.
