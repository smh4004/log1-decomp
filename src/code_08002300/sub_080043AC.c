/* sub_080043AC  (original: 0x080043AC-0x08004406 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


int sub_080043AC(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar4 = 0;
  iVar7 = (uint)*param_2 + (uint)param_2[1] * 0x100;
  pbVar5 = param_2 + 2;
  while (iVar7 != 0) {
    iVar7 = iVar7 + -1;
    bVar1 = *pbVar5;
    uVar3 = (uint)pbVar5[1];
    pbVar5 = pbVar5 + 2;
    if (uVar3 == 0) {
      uVar3 = 0x100;
    }
    iVar4 = iVar4 + (uint)bVar1;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      iVar2 = iVar4 * 3;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2) = *pbVar5;
      pbVar6 = pbVar5 + 2;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 1) = pbVar5[1];
      pbVar5 = pbVar5 + 3;
      iVar4 = iVar4 + 1;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 2) = *pbVar6;
    }
  }
  *(undefined2 *)(param_1 + 0x1c) = 1;
  return param_1;
  return param_1;   /* ADS constructor: returns this */
}
