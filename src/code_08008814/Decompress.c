/* Decompress  (original: 0x08009524-0x08009586 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_0202c224;
extern undefined4 volatile gUnknown_080116C0;

/* Decompress(src, flags): runs the BIOS decompressors selected by flags in this order, each one's output feeding the
   next: bit 4 Huffman (swi 0x13), bit 3 LZ77 (swi 0x11), bit 2 run-length (swi 0x14), bit 1 Diff16 (swi 0x18),
   bit 0 Diff8 (swi 0x16). The outputs alternate between the two buffers in gUnknown_080116C0. Returns the last
   output (or src if no bit is set). Written by hand: Ghidra can't express the BIOS calls. */
#define BIOS(n, s, d) do { register undefined4 _r0 __asm__("r0") = (undefined4)(s); \
    register undefined4 _r1 __asm__("r1") = (undefined4)(d); \
    __asm__ volatile ("swi " #n : "+r"(_r0), "+r"(_r1) : : "r2", "r3", "memory"); } while (0)

undefined4 Decompress(undefined4 param_1, int param_2)
{
  uint i = 0;
  undefined4 dst;

  if (param_2 & 0x10) { dst = (&gUnknown_080116C0)[0]; BIOS(0x13, param_1, dst); param_1 = dst; i = 1; }
  if (param_2 & 8) { dst = (&gUnknown_080116C0)[i]; i = (i + 1) & 1; BIOS(0x11, param_1, dst); param_1 = dst; }
  if (param_2 & 4) { dst = (&gUnknown_080116C0)[i]; i = (i + 1) & 1; BIOS(0x14, param_1, dst); param_1 = dst; }
  if (param_2 & 2) { dst = (&gUnknown_080116C0)[i]; i = (i + 1) & 1; BIOS(0x18, param_1, dst); param_1 = dst; }
  if (param_2 & 1) { dst = (&gUnknown_080116C0)[i]; BIOS(0x16, param_1, dst); param_1 = dst; }
  return param_1;
}
