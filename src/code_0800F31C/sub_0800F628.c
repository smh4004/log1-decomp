/* sub_0800F628  (original: 0x0800F628-0x0800F69E in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 33% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800F628(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar1 = *param_3;
  *param_3 = iVar1 + 1;
  puVar5 = (undefined4 *)((iVar1 + 1) * 0x14 + param_2);
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  *puVar5 = *param_1;
  puVar5[1] = uVar3;
  puVar5[2] = uVar4;
  uVar3 = param_1[4];
  puVar5[3] = param_1[3];
  puVar5[4] = uVar3;
  iVar1 = *param_3;
  if (1 < iVar1) {
    while ((iVar1 = iVar1 + -1, 1 < iVar1 &&
           (puVar5 = (undefined4 *)(iVar1 * 0x14 + param_2), (int)puVar5[3] < (int)puVar5[-2]))) {
      uVar3 = puVar5[2];
      uVar6 = *puVar5;
      uVar7 = puVar5[1];
      uVar4 = puVar5[3];
      uVar2 = puVar5[4];
      *puVar5 = puVar5[-5];
      puVar5[1] = puVar5[-4];
      puVar5[2] = puVar5[-3];
      puVar5[3] = puVar5[-2];
      puVar5[4] = puVar5[-1];
      puVar5[-1] = uVar2;
      puVar5[-2] = uVar4;
      puVar5[-3] = uVar3;
      puVar5[-5] = uVar6;
      puVar5[-4] = uVar7;
    }
  }
  return;
}

