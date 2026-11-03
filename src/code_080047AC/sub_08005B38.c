/* sub_08005B38  (original: 0x08005B38-0x08005BB4 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int volatile DAT_03000604;
extern int volatile DAT_03000980;
extern undefined volatile DAT_0200a824;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08005B38(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  __call_via_r1(param_1,(undefined *)(*(int *)(*param_1 + 0x18) + *param_1));
  DAT_03000980 = (uint)*(byte *)(DAT_03000604 + 1) + DAT_03000980;
  uVar1 = 0;
  iVar2 = (uint)*(ushort *)(DAT_03000604 + 2) * 0x40 + 0x6000000;
  if (*(short *)(DAT_03000604 + 4) != 0) {
    do {
      REG_DMA3SAD = &DAT_0200a824 +
                    ((uVar1 & ~(uint)*(byte *)(DAT_03000604 + 7)) +
                    (uVar1 + (DAT_03000980 >> 6) & (uint)*(byte *)(DAT_03000604 + 7))) * 0x40;
      REG_DMA3DAD = iVar2;
      Ram040000dc = 0x10;
      DAT_040000de = 0x8400;
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x40;
    } while ((int)uVar1 < (int)(uint)*(ushort *)(DAT_03000604 + 4));
  }
  __call_via_r1(param_1,(undefined *)(*(int *)(*param_1 + 0x1c) + *param_1));
  return;
}

