# Original toolchain: ARM ADS 1.x (tcpp + armlink), as in Buu's Fury

Legacy of Goku II was built with the same toolchain as Buu's Fury (`../buusfury-decomp/docs/toolchain.md` has the full
argument): ARM's Developer Suite C++ compiler for Thumb (`tcpp`), linked with `armlink` against the ARM C library.
Checked in this ROM (bus addresses):

| Observation | Where | Why it points to ADS |
|---|---|---|
| Signed divide entered through `bx pc; nop` into ARM code, divisor in r0, dividend in r1 | `__16__rt_sdiv` 0x08021F30 -> `__rt_sdiv` 0x08021F34 | ARM C library `__rt_sdiv`, not libgcc `__divsi3` |
| `__call_via_r0`..`r7`: eight `bx rN` halfwords | 0x08021D28 | ADS interworking helpers for indirect calls |
| `push {r3, lr}` in leaf-ish functions | everywhere | ADS keeps the stack 8-byte aligned (PRESERVE8) |
| Constant strings inside the code area next to their users (`K:\Source\AreaEntry.cpp` 0x0800EBDC) | text | armcc/tcc put literals in the code AREA; GCC uses `.rodata` |
| `C$$pi_ctorvec`: entry-relative offsets to static constructors | 0x08023588-0x0802369B | armlink C++ static init |
| Base-relative vtables (entries are `func - vtable`) | 0x08023720-0x08026047 | ADS C++ ABI |
| armlink veneers (`bx pc; nop; ldr pc, =target`) into the IWRAM routines | 0x0802369C-0x0802371F | armlink interworking veneers |
| ADS switch idiom `cmp; bhs; adr; ldrb/ldrh; lsl; add pc` | several | tcc jump tables |

Consequence: the matching layer is assembly. The C decompilation (`docs/decomp.md`) is compiled with GCC and checked for
behaviour, not bytes.
