# Shiftability: making every pointer symbolic

`make shift-test` builds `log1_shift.gba` with `SHIFT` bytes of padding right after crt0, so every byte of code and data
moves, plays `tools/harness/long.txt` (intro movie, title, new game, story, the first area, menu, 60 random walks with
attacks) on both ROMs and compares a frame hash at every checkpoint.

Current result: **37 of 37 checkpoints identical** with `SHIFT=0x100`.

Legacy of Goku has no WFZ containers: almost all of its 7.6 MB of data is raw or packed with the GBA BIOS coders, so
pointer-looking words in data are far more common than in the sequels (about 7,050 words are rejected, 9,432 accepted).
The classifier (`tools/bfdis/ptrs.py`) is shared with Legacy of Goku II and Buu's Fury; these rules were added for this
game (switched on in `config/game.json`):

| Symptom in the shifted ROM | Cause | Fix |
|---|---|---|
| Movie decoded garbage after the logos | BIOS Huffman/LZ77 streams contain pointer-looking words | `bios_blocks`: `tools/bfdis/lz.py` decodes every word-aligned stream a ROM word points to; its bytes are compressed data (like WFZ) |
| Movie stalled after 2 frames | the three movie streams (custom codec) are 3.5 MB of noise | `noptr` ranges for the movie streams |
| A fade colour off by one | a palette word `0x08424210` (two BGR555 colours) was converted | `palette_filter`; and isolated far words need a target that is a known object |
| Wrong music notes | repeated byte patterns in sequence data (`00 13 3C 08`) accepted because they appeared 9 times | `isolated_refcount: 0`: repetition alone is not evidence |
| A whole table hidden | a false run-length stream "decoded" over a pointer table | run-length streams are not scanned (the game only applies RLE to RAM) |
| State machine never advanced | ROM objects `{vtable*, ...}` whose method tables are absolute | `methods`: a pointer to a run of function pointers, or to an object starting with one, is a pointer |
| Map loader read the wrong record | an isolated pointer to an array of pointers | `ptrarray` |
| Wrong sprite pixels | frame records point at the pixels right after themselves | `inline`: a word pointing 4-16 bytes past itself is a pointer |

| (found by the conversation editor, not the route) 46 text pointers left raw, e.g. most enemy names and some conversation lines | records in tables point at C strings that start at odd or unaligned addresses, so the stride rule's aligned-target check refused them | `string_tables`: a word in a pointer table (a pointer within 16 bytes) whose target is the start of a C string (after a NUL, 3+ printable characters with letters) is a pointer |

How each was found: `tools/harness/shiftdiff.py` (first differing frame and memory), then harness `watchon` on a differing
word in both ROMs, `hitlog` (every function entry with r0-r3, normalised for the shift) to find the first call whose
arguments differ, and `tracepc` on that function. Each rule was checked to keep Legacy of Goku II at 37/37 as well.
