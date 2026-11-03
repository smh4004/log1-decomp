/* sub_080095FE  (original: 0x080095FE-0x08009626 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_080095FE(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  do {
    uVar1 = 0x1000;
    if (param_4 < 0x1000) {
      uVar1 = param_4;
    }
    param_4 = param_4 - uVar1;
    *param_1 = param_3;
    param_1[1] = param_2;
    *(short *)(param_1 + 2) = (short)(uVar1 >> 1);
    *(undefined2 *)((int)param_1 + 10) = 0x8000;
    param_2 = param_2 + uVar1;
    param_3 = param_3 + uVar1;
  } while (param_4 != 0);
  return;
}

