/* sub_08003E02  (original: 0x08003E02-0x080040F0 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 95% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800E640();
extern byte volatile DAT_030007b1;
extern int volatile DAT_030007c8;
extern uint volatile DAT_030007c4;
extern int volatile DAT_030007d0;
extern uint volatile DAT_030007cc;
extern undefined volatile DAT_0202be24;
extern undefined volatile DAT_0202be28;
extern undefined4 volatile DAT_08011004;
extern undefined * volatile gUnknown_08010FE8;
extern undefined4 volatile gUnknown_08011214;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08003E02(int param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  
  REG_DMA3SAD = 0x85c0f34;
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0x1ff00ff) + 0x40000000;
  *puVar5 = uVar7;
  uVar8 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       ((uint)*(byte *)(param_1 + 0xd) << 0x1c) >> 0x10 | uVar8 & 0xffff0fff;
  *puVar5 = ((uVar7 & 0xfe00ffff) + 0x80000 & 0xffffff00) + 8;
  iVar4 = *(int *)(param_2 + 2);
  *(int *)(param_2 + 2) = iVar4 + 0x80;
  param_2[1] = param_2[1] + 4;
  REG_DMA3SAD = *(undefined4 *)((&gUnknown_08010FE8)[DAT_030007b1] + 4);
  REG_DMA3DAD = iVar4 + 0x80;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0x1ff00ff) + 0x40000000;
  *puVar5 = uVar7;
  uVar8 = (*(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000 | param_2[1] & 0x3ff) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       uVar8 & 0xffff0fff | ((uint)*(byte *)(param_1 + 0xd) << 0x1c) >> 0x10;
  *puVar5 = ((uVar7 & 0xfe00ffff) + 0x480000 & 0xffffff00) + 8;
  iVar6 = *(int *)(param_2 + 2) + 0x80;
  *(int *)(param_2 + 2) = iVar6;
  param_2[1] = param_2[1] + 4;
  REG_DMA3SAD = 0x85c0e88;
  REG_DMA3DAD = iVar6;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0x1ff00ff) + 0x40000000;
  *puVar5 = uVar7;
  uVar8 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       uVar8 & 0xffff0fff | ((uint)*(byte *)(param_1 + 0x14) << 0x1c) >> 0x10;
  *puVar5 = ((uVar7 & 0xfe00ffff) + 0x180000 & 0xffffff00) + 8;
  iVar4 = *(int *)(param_2 + 2);
  *(int *)(param_2 + 2) = iVar4 + 0x80;
  param_2[1] = param_2[1] + 4;
  REG_DMA3SAD = 0x85c0fe0;
  REG_DMA3DAD = iVar4 + 0x80;
  Ram040000dc = 0x40;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0xffff00ff) + 0x4000;
  *puVar5 = uVar7;
  uVar7 = (uVar7 & 0x1ffffff) + 0x80000000;
  *puVar5 = uVar7;
  uVar8 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       ((uint)*(byte *)(param_1 + 0x14) << 0x1c) >> 0x10 | uVar8 & 0xffff0fff;
  *puVar5 = ((uVar7 & 0xfe00ffff) + 0x280000 & 0xffffff00) + 8;
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x100;
  param_2[1] = param_2[1] + 8;
  iVar2 = sub_0800E640(DAT_030007c4,DAT_030007c8 * 0x2c);
  iVar4 = sub_0800E640(DAT_030007cc,DAT_030007d0 * 0x2c);
  if (0x2c < iVar2) {
    iVar2 = 0x2c;
  }
  if (0x2c < iVar4) {
    iVar4 = 0x2c;
  }
  piVar3 = &gUnknown_08011214;
  for (; 1 < iVar4; iVar4 = iVar4 + -2) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xcc;
    piVar9 = piVar3 + 2;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xcc;
    piVar3 = piVar3 + 3;
    *(undefined1 *)(iVar6 + *piVar9) = 0xee;
  }
  if (iVar4 != 0) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xac;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xac;
    *(undefined1 *)(iVar6 + piVar3[2]) = 0xae;
  }
  piVar3 = &DAT_08011004;
  for (; 1 < iVar2; iVar2 = iVar2 + -2) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xbb;
    piVar9 = piVar3 + 2;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xbb;
    piVar3 = piVar3 + 3;
    *(undefined1 *)(iVar6 + *piVar9) = 0xdd;
  }
  if (iVar2 != 0) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xab;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xab;
    *(undefined1 *)(iVar6 + piVar3[2]) = 0xad;
  }
  return;
}

