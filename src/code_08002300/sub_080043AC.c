/* sub_080043AC  (original: 0x080043AC-0x08004406 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 5/5 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


int sub_080043AC(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = (uint)*param_2 + (uint)param_2[1] * 0x100;
  param_2 = param_2 + 2;
  while (iVar6 != 0) {
    iVar6 = iVar6 + -1;
    bVar1 = *param_2;
    uVar3 = (uint)param_2[1];
    param_2 = param_2 + 2;
    if (uVar3 == 0) {
      uVar3 = 0x100;
    }
    iVar4 = iVar4 + (uint)bVar1;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      iVar2 = iVar4 * 3;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2) = *param_2;
      pbVar5 = param_2 + 2;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 1) = param_2[1];
      param_2 = param_2 + 3;
      iVar4 = iVar4 + 1;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 2) = *pbVar5;
    }
  }
  *(undefined2 *)(param_1 + 0x1c) = 1;
  return param_1;
  return param_1;   /* ADS constructor: returns this */
}
