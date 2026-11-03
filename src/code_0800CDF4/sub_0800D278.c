/* sub_0800D278  (original: 0x0800D278-0x0800D3B8 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 86% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080095D0();
extern int sub_08004EF4();
extern int sub_08009626();
extern undefined4 volatile DAT_03004638;
extern byte volatile DAT_03004635;
extern short * volatile DAT_03000600;
extern byte volatile DAT_03004634;
extern short volatile DAT_0300463a;
extern undefined4 volatile DAT_030047ec;
extern byte volatile DAT_03004636;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)
#define _DAT_03004638 (*(undefined4 volatile *)0x03004638)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800D278(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short local_20;
  short local_1e;
  
  uVar1 = *param_2;
  local_1e = 0;
  if (DAT_03004635 != 0) {
    do {
      local_20 = 0;
      if (DAT_03004634 != 0) {
        DAT_0300463a = (short)(uVar1 >> 0x10);
        do {
          iVar2 = 0;
          iVar4 = (local_1e * 2 + (int)local_20) * 0x4b0;
          do {
            iVar3 = *(int *)(((int)*DAT_03000600 * (int)(short)(DAT_0300463a + local_1e) +
                             (int)(short)(((uVar1 & 0xffff) + (int)local_20) * 0x10000 >> 0x10)) * 4
                            + *(int *)(DAT_03000600 + iVar2 * 2 + 0x10));
            if (iVar3 == 0) {
              DAT_030047ec = 0;
              REG_DMA3SAD = 0x30047ec;
              REG_DMA3DAD = iVar4 + iVar2 * 0x12c0 + 0x2000000;
              Ram040000dc = 300;
              DAT_040000de = 0x8500;
            }
            else {
              REG_DMA3SAD = iVar3;
              REG_DMA3DAD = iVar4 + iVar2 * 0x12c0 + 0x2000000;
              Ram040000dc = 300;
              DAT_040000de = 0x8400;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 3);
          local_20 = local_20 + 1;
        } while (local_20 < (short)(ushort)DAT_03004634);
      }
      local_1e = local_1e + 1;
    } while (local_1e < (short)(ushort)DAT_03004635);
  }
  _DAT_03004638 = uVar1;
  uVar1 = sub_08004EF4(DAT_03000600,(short *)param_2);
  if ((uVar1 != 0) && (DAT_03004636 != uVar1)) {
    DAT_03004636 = (byte)uVar1;
    iVar2 = sub_080095D0(*(undefined4 **)(*(int *)(DAT_03000600 + 0xe) + (uVar1 & 0xff) * 4 + -4));
    sub_08009626(&REG_DMA3SAD,0x6005680,iVar2,0x8980);
  }
  return;
}

