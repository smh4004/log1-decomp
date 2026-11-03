# Hand-written C

`autodecomp.py tus` uses `NAME.c` from this folder instead of Ghidra's text for function `NAME`. The file holds
only the function definition (plus any `static` helpers or `#define`s it needs). The generator still adds
`include/ghidra_types.h` and an `extern` for every callee and global Ghidra listed for that function, so use
Ghidra's names (`DAT_xxxxxxxx`, `gUnknown_...`, `sub_...`, `REG_...`). A hand-written function goes through the same
compile and equivalence tests as the generated ones; nothing is accepted on trust.

Each file starts with a comment saying what the function does and why Ghidra's version couldn't be used.

| Why | Functions |
|---|---|
| BIOS calls (Ghidra writes `software_interrupt(n)` and loses the results) | `Decompress` (Huffman / LZ77 / RLE / Diff chain), `sub_0800A80E` (four `Div` calls), `sub_0800DBF8` (SoftReset), `sub_0800E9A0`, `sub_0800EC6C` (ARM semihosting, from the ADS library) |
| Variadic (`push {r0-r3}`, arguments walked on the stack) | `sub_08008CE8` (forwards a `va_list`), `sub_08008E3A` (the game's printf-style text formatter) |
| A divide's remainder used from r1 (Ghidra's `extraout_r1`) | `sub_08001CFA`, `sub_08001DAE` |
| GCC-style returns (`pop {r1}; bx r1`) misread as jump tables, or returning `lr` (`in_lr`) | `sub_0800E130`, `sub_0800E1FC`, `sub_0800E27C`, `sub_0800E32C`, `sub_0800E408`, `sub_0800E460`, `sub_0800E95C`, `sub_0800E9B0` (Nintendo's EEPROM save library and the ADS heap) |
| Partial-variable notation Ghidra can't express in C | `sub_0800CC60` |
| Scratch stack slot from `push {r3}` (looked variadic to an older check) | `sub_0800B3FC`, `sub_0800B758`, `sub_0800F3C4`, `sub_0800F420` |

Two functions have no C equivalent at all and stay assembly (see `config/decomp_blocklist.txt`): `sub_08000520`
returns through another function's stack frame, and `sub_0800E8A0` continues in code that uses its frame.
