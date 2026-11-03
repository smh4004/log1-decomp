/* sub_0800A06C  (original: 0x0800A06C-0x0800A090 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A06C(undefined4 *param_1)

{
  int *piVar1;
  
  sub_08009A20(param_1);
  if ((*(byte *)(param_1 + 6) & 0x11) != 0) {
    piVar1 = (int *)param_1[8];
    *piVar1 = (uint)*(byte *)((int)param_1 + 0x1e) << 0x16;
    *(byte *)(piVar1 + 3) = *(byte *)(piVar1 + 3) & 0xfb;
  }
  return;
}

