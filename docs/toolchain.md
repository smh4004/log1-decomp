# Original toolchain: ARM C++ (SDT/ADS family), not GCC

Checked in this ROM (bus addresses):

| Observation | Where | Meaning |
|---|---|---|
| Signed divide entered through `bx pc; nop` into ARM code, divisor in r0, dividend in r1 | `__16__rt_sdiv` 0x0800E568 -> `__rt_sdiv` 0x0800E56C (same bytes as in Legacy of Goku II) | ARM C library, not libgcc |
| `__call_via_r0`..`r7` | 0x0800E4A0 | ARM interworking helpers |
| `C$$pi_ctorvec` (27 entries), base-relative vtables, "Pure virtual fn called", "C++ library exception" | 0x0800EE54, 0x0800EED8, rodata | ARM C++ runtime |
| Functions return with `pop {pc}` (2,225 times; GCC interworking code uses `pop {rN}; bx rN`) and save registers with `push {lr}` / `push {r4, lr}`, **without** the `push {r3, lr}` 8-byte stack alignment seen in Legacy of Goku II | everywhere | an ARM compiler older than the ADS 1.1+ used for the sequels (SDT 2.5x or ADS 1.0) |
| No RW image copied by crt0; the game copies its own IWRAM routines | crt0 0x080000C0 | Nintendo-SDK-style start-up (`IntrMain` table dispatcher at 0x08000138) |

Consequence: as for the sequels, the matching layer is assembly, and the C decompilation is GCC code checked for
behaviour, not bytes.
