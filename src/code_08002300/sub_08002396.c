/* sub_08002396  (original: 0x08002396-0x080023EE in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08002396(short *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  
  sVar1 = *(short *)(param_2 + 0x20);
  iVar6 = *(int *)(param_2 + 0x1c) + (uint)*(byte *)(param_2 + 0x13) * 8;
  sVar2 = *(short *)(param_2 + 0x22);
  sVar3 = *(short *)(iVar6 + 6);
  sVar4 = *(short *)(iVar6 + 8);
  sVar5 = *(short *)(iVar6 + 10);
  *param_1 = *(short *)(iVar6 + 4) + sVar1;
  param_1[1] = sVar3 + sVar2;
  param_1[2] = sVar4 + sVar1;
  param_1[3] = sVar5 + sVar2;
  return;
}

