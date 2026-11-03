/* sub_08002A16  (original: 0x08002A16-0x08002A34 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 76% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002E80();
extern int sub_08002466();
extern ushort volatile DAT_03003d12;


void sub_08002A16(int param_1)

{
  if (((uint)DAT_03003d12 << 0x18) >> 0x1c == 0) {
    sub_08002466(param_1,0);
  }
  sub_08002E80(param_1);
  return;
}

