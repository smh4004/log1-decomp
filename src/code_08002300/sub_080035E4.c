/* sub_080035E4  (original: 0x080035E4-0x0800370C in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int volatile DAT_03000800;
extern undefined4 volatile DAT_030047ec;
extern undefined volatile DAT_0202be24;
extern undefined volatile DAT_0202be28;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080035E4(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_1c;
  
  iVar3 = *(int *)(DAT_03000800 + 0x1c) + (uint)*(byte *)(DAT_03000800 + 0x13) * 8;
  uVar2 = *(short *)(iVar3 + 6) + 0x88;
  local_1c = CONCAT22(uVar2,*(short *)(iVar3 + 4) + 0xd0);
  iVar7 = (int)*(short *)(iVar3 + 8) - (int)*(short *)(iVar3 + 4);
  iVar3 = (int)*(short *)(iVar3 + 10) - (int)*(short *)(iVar3 + 6);
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  *puVar5 = *puVar5 & 0xc1ff00ff | 0xc0000000;
  uVar10 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar10;
  *(uint *)(&DAT_0202be28 + iVar4) =
       uVar10 & 0xffff0fff | ((uint)*(byte *)(param_1 + 0xd) << 0x1c) >> 0x10;
  *puVar5 = uVar2 & 0xff | (uint)(local_1c << 0x17) >> 7 | 0xc0000000;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x200;
  DAT_040000de = 0x8500;
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      iVar8 = *(int *)(param_2 + 2) + ((uint)(iVar4 << 0x1d) >> 0x1b) + (iVar4 >> 3) * 0x100;
      iVar6 = 0;
      if (0 < iVar7) {
        do {
          bVar9 = 0x10;
          if (-1 < iVar6 << 0x1f) {
            bVar9 = 1;
          }
          iVar11 = (iVar6 >> 3) * 0x20 + ((uint)(iVar6 << 0x1d) >> 0x1e);
          iVar6 = iVar6 + 1;
          *(byte *)(iVar8 + iVar11) = bVar9 | *(byte *)(iVar8 + iVar11);
        } while (iVar6 < iVar7);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x800;
  param_2[1] = param_2[1] + 0x40;
  return;
}

