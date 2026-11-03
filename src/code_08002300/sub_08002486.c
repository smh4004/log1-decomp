/* sub_08002486  (original: 0x08002486-0x080024B8 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005EA6();
extern int __call_via_r1();


void sub_08002486(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  
  *(int *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  uVar1 = sub_08005EA6(*(int *)(param_2 + 0x24));
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + param_4 * 0x10;
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x18) + param_4 * 0x14);
  *(undefined4 **)(param_1 + 0x34) = puVar2;
  __call_via_r1(param_1,(undefined *)*puVar2);
  return;
}

