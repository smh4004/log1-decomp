/* sub_0800293C  (original: 0x0800293C-0x0800295E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 81% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005478();


void sub_0800293C(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x40) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    if (bVar1 == 0x3f) {
      sub_08005478(2,(uint)*(byte *)(param_1 + 0x15));
    }
  }
  return;
}

