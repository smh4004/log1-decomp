/* sub_08003524  (original: 0x08003524-0x08003550 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 95% of instructions covered.
 */
#include "ghidra_types.h"
extern byte volatile DAT_0300004d;
extern byte volatile DAT_030007b1;


void sub_08003524(void)

{
  do {
    DAT_030007b1 = DAT_030007b1 + 1;
    if (2 < DAT_030007b1) {
      DAT_030007b1 = 0;
      return;
    }
  } while (((uint)DAT_0300004d & 1 << (uint)DAT_030007b1) == 0);
  return;
}

