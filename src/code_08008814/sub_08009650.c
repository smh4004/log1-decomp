/* sub_08009650  (original: 0x08009650-0x08009680 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined2 volatile DAT_030047e8;


void sub_08009650(undefined4 *param_1,int param_2,undefined2 param_3,uint param_4)

{
  uint uVar1;
  
  do {
    uVar1 = 0x1000;
    if (param_4 < 0x1000) {
      uVar1 = param_4;
    }
    DAT_030047e8 = param_3;
    *param_1 = &DAT_030047e8;
    param_4 = param_4 - uVar1;
    param_1[1] = param_2;
    *(short *)(param_1 + 2) = (short)(uVar1 >> 1);
    *(undefined2 *)((int)param_1 + 10) = 0x8100;
    param_2 = param_2 + uVar1;
  } while (param_4 != 0);
  return;
}

