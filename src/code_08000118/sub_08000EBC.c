/* sub_08000EBC  (original: 0x08000EBC-0x08000F58 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 23% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08000EBC(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar6;
  unsigned int __frame[261];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_414 ((ushort *)((char *)__frame + 0x0))
  uint uVar5;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    __call_via_r1(piVar1,(undefined *)(*(int *)(*piVar1 + 8) + *piVar1));
  }
  if ((int)((uint)*(byte *)(param_1 + 4) << 0x1f) < 0) {
    REG_DMA3SAD = 0x5000000;
    REG_DMA3DAD = local_414;
    Ram040000dc = 0x100;
    DAT_040000de = 0x8400;
    iVar2 = 0;
    do {
      uVar3 = (uint)local_414[iVar2];
      uVar5 = (uVar3 & 0x1f) + 1;
      uVar4 = (ushort)uVar5;
      uVar6 = ((uVar3 << 0x16) >> 0x1b) + 1;
      uVar3 = ((uVar3 << 0x11) >> 0x1b) + 1;
      if (0x1f < uVar5) {
        uVar4 = 0x1f;
      }
      if (0x1f < uVar6) {
        uVar6 = 0x1f;
      }
      if (0x1f < uVar3) {
        uVar3 = 0x1f;
      }
      local_414[iVar2] = (ushort)(uVar3 << 10) | uVar4 | (ushort)(uVar6 << 5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x200);
    REG_DMA3SAD = local_414;
    REG_DMA3DAD = 0x5000000;
    Ram040000dc = 0x100;
    DAT_040000de = 0x8400;
  }
  *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
  return;
}

