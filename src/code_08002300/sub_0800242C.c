/* sub_0800242C  (original: 0x0800242C-0x08002450 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 2/2 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800242C(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x34);
  *(int *)(param_1 + 0x2c) = iVar1;
  *(int *)(param_1 + 0x34) = param_2 + ((*(int *)(param_1 + 0x34) - iVar1) * 0xccd >> 0x10) * 0x14;
  return;
}

