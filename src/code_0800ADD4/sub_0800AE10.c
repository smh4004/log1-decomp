/* sub_0800AE10  (original: 0x0800AE10-0x0800AEC6 in asm/code_0800ADD4.s)
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


void sub_0800AE10(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar2 = (uint)uVar1 * 8;
  puVar3 = (uint *)(&DAT_0202be24 + iVar2);
  uVar4 = *puVar3;
  *puVar3 = uVar4 & 0xffffc0ff;
  uVar6 = ((uint)*(byte *)((int)param_1 + 0xf) << 0x1e) >> 0x10;
  *puVar3 = uVar6 | uVar4 & 0xc1ff00ff;
  uVar5 = (uint)(byte)param_1[7] << 0x1e;
  *puVar3 = uVar5 | uVar6 | uVar4 & 0x1ff00ff;
  uVar1 = param_2[1];
  uVar7 = *(uint *)(&DAT_0202be28 + iVar2);
  *(uint *)(&DAT_0202be28 + iVar2) = uVar1 & 0x3ff | uVar7 & 0xfffffc00 | 0xc00;
  *(uint *)(&DAT_0202be28 + iVar2) =
       uVar1 & 0x3ff | uVar7 & 0xffff0c00 | 0xc00 |
       ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
  uVar7 = ((uint)*param_1 << 0x17) >> 7;
  *puVar3 = uVar5 | uVar6 | uVar4 & 0xff | uVar7;
  *puVar3 = uVar5 | uVar6 | uVar7 | param_1[1] & 0xff;
  REG_DMA3SAD = *(undefined4 *)(param_1 + 4);
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = (short)(((uint)*(byte *)((int)param_1 + 0x11) << 5) >> 2);
  DAT_040000de = 0x8400;
  *(uint *)(param_2 + 2) = *(int *)(param_2 + 2) + (uint)*(byte *)((int)param_1 + 0x11) * 0x20;
  param_2[1] = param_2[1] + (ushort)*(byte *)((int)param_1 + 0x11);
  return;
}

