/* sub_0800F588  (original: 0x0800F588-0x0800F628 in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


undefined4 * sub_0800F588(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  iVar2 = *param_3;
  *param_3 = iVar2 + 1;
  puVar10 = (undefined4 *)((iVar2 + 1) * 0x14 + param_2);
  uVar3 = param_1[1];
  uVar8 = param_1[2];
  *puVar10 = *param_1;
  puVar10[1] = uVar3;
  puVar10[2] = uVar8;
  uVar3 = param_1[4];
  puVar1 = param_1 + 5;
  puVar10[3] = param_1[3];
  puVar10[4] = uVar3;
  iVar2 = *param_3;
  if (1 < iVar2) {
    puVar1 = (undefined4 *)(iVar2 * 0x14 + param_2);
    uVar3 = *puVar1;
    uVar8 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    puVar1 = (undefined4 *)puVar1[4];
    *(undefined4 *)(param_2 + 0x10) = 0xfffe7960;
    iVar6 = *(int *)((iVar2 >> 1) * 0x14 + param_2 + 0x10);
    while ((int)puVar1 < iVar6) {
      puVar11 = (undefined4 *)(iVar2 * 0x14 + param_2);
      puVar10 = (undefined4 *)((iVar2 >> 1) * 0x14 + param_2);
      uVar7 = puVar10[1];
      uVar9 = puVar10[2];
      *puVar11 = *puVar10;
      puVar11[1] = uVar7;
      puVar11[2] = uVar9;
      uVar7 = puVar10[4];
      puVar11[3] = puVar10[3];
      puVar11[4] = uVar7;
      iVar6 = *(int *)((iVar2 >> 2) * 0x14 + param_2 + 0x10);
      iVar2 = iVar2 >> 1;
    }
    puVar10 = (undefined4 *)(iVar2 * 0x14 + param_2);
    puVar10[4] = puVar1;
    puVar10[3] = uVar5;
    puVar10[2] = uVar4;
    puVar10[1] = uVar8;
    *puVar10 = uVar3;
  }
  return puVar1;
}

