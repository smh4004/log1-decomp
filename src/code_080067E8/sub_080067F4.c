/* sub_080067F4  (original: 0x080067F4-0x0800689A in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_0202be24;
extern undefined volatile DAT_0202be28;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080067F4(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  REG_DMA3SAD = *(undefined4 *)(param_1 + 4);
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar2 = (uint)uVar1 * 8;
  puVar3 = (uint *)(&DAT_0202be24 + iVar2);
  uVar4 = (*puVar3 & 0x1ff00ff) + 0x40000000;
  *puVar3 = uVar4;
  uVar5 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar2) & 0xfffff000) + 0x800;
  *(uint *)(&DAT_0202be28 + iVar2) = uVar5;
  *(uint *)(&DAT_0202be28 + iVar2) =
       uVar5 & 0xffff0fff | ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
  uVar5 = ((uint)*param_1 << 0x17) >> 7;
  *puVar3 = uVar4 & 0xfe00ffff | uVar5;
  *puVar3 = param_1[1] & 0xff | uVar4 & 0xfe00ff00 | uVar5;
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x80;
  param_2[1] = param_2[1] + 4;
  return;
}

