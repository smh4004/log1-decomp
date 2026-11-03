/* sub_08003D94  (original: 0x08003D94-0x08003DBE in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005EA6();


void sub_08003D94(undefined2 *param_1)

{
  undefined1 uVar1;
  
  *param_1 = 8;
  param_1[1] = 8;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 6) = 0x10;
  uVar1 = sub_08005EA6(0x85c0fb4);
  *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  uVar1 = sub_08005EA6(0x85c0f08);
  *(undefined1 *)(param_1 + 10) = uVar1;
  return;
}

