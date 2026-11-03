/* sub_0800106C  (original: 0x0800106C-0x08001174 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 93% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800D278();
extern int sub_08008764();
extern int sub_080095D0();
extern int sub_08009626();
extern byte volatile DAT_03004636;
extern byte volatile DAT_03004634;
extern byte volatile DAT_03004635;
extern undefined volatile DAT_030005f0;
extern short volatile DAT_030005f2;
extern ushort volatile DAT_03004638;
extern ushort volatile DAT_0300463a;
extern short volatile DAT_03000608;
extern short volatile DAT_0300060a;
extern int volatile DAT_03000600;
extern int volatile DAT_03000604;
extern undefined4 volatile DAT_03000980;
extern ushort volatile DAT_030005f4;
extern ushort volatile DAT_030005f6;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define _DAT_030005f0 (*(undefined4 volatile *)0x030005F0)
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800106C(undefined4 param_1)

{
  int iVar1;
  unsigned int __frame[7];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_1c (*(undefined4 *)((char *)__frame + 0x0))
#define local_18 (*(short *)((char *)__frame + 0x4))
#define local_16 (*(short *)((char *)__frame + 0x6))
  DAT_03004636 = 0;
  DAT_03004634 = 2;
  DAT_03004635 = 2;
  if (_DAT_030005f0 < 2) {
    DAT_03004634 = 1;
  }
  if (DAT_030005f2 < 2) {
    DAT_03004635 = 1;
  }
  DAT_03004638 = 0xffff;
  DAT_0300463a = 0xffff;
  local_18 = (short)(DAT_03000608 * 0x445 >> 0x12);
  iVar1 = (int)_DAT_030005f0 - (uint)DAT_03004634;
  if (iVar1 < local_18) {
    local_18 = (short)iVar1;
  }
  local_16 = (short)(DAT_0300060a * 0x667 >> 0x12);
  if ((int)((int)DAT_030005f2 - (uint)DAT_03004635) < (int)local_16) {
    local_16 = DAT_030005f2 - (ushort)DAT_03004634;
  }
  sub_0800D278(param_1,(uint *)&local_18);
  REG_DMA3SAD = 0x85c3868;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  if (*(undefined4 **)(DAT_03000600 + 0x30) != (undefined4 *)0x0) {
    iVar1 = sub_080095D0(*(undefined4 **)(DAT_03000600 + 0x30));
    sub_08009626(&REG_DMA3SAD,0x6002480,iVar1,0x3200);
    if ((DAT_03000604 != 0) && (*(ushort *)(DAT_03000604 + 4) != 0)) {
      REG_DMA3SAD = (uint)*(ushort *)(DAT_03000604 + 2) * 0x40 + 0x6000000;
      REG_DMA3DAD = 0x200a824;
      Ram040000dc = (short)(((uint)*(ushort *)(DAT_03000604 + 4) << 6) >> 2);
      DAT_040000de = 0x8400;
    }
    DAT_03000980 = 0;
  }
  REG_DMA3SAD = *(int *)(DAT_03000600 + 0x2c) + 0x20;
  REG_DMA3DAD = 0x5000020;
  Ram040000dc = 0x78;
  DAT_040000de = 0x8400;
  local_1c = CONCAT22(DAT_030005f6,DAT_030005f4);
  sub_08008764(local_1c);
  return;
}

