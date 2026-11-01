/* sub_080031E2  (original: 0x080031E2-0x080031FA in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 10/10 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_030007dc;
extern int volatile DAT_030007b4;


void sub_080031E2(void)

{
  DAT_030007dc = 0;
  if (DAT_030007b4 != 0) {
    *(byte *)(DAT_030007b4 + 0xc) = *(byte *)(DAT_030007b4 + 0xc) & 0xfe;
    DAT_030007b4 = 0;
  }
  return;
}

