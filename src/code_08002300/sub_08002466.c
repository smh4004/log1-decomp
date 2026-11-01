/* sub_08002466  (original: 0x08002466-0x08002486 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_08002466(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + param_2 * 0x10;
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x18) + param_2 * 0x14);
  *(undefined4 **)(param_1 + 0x34) = puVar1;
  __call_via_r1(param_1,*puVar1,*(int *)(param_1 + 0x18),param_2 * 4,param_4);
  return;
}

