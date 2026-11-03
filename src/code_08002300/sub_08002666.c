/* sub_08002666  (original: 0x08002666-0x080026DE in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 96% of instructions covered.
 */
#include "ghidra_types.h"
extern int volatile DAT_03000610;
extern undefined4 volatile DAT_03000614;
extern undefined4 volatile DAT_03000618;
extern undefined1 volatile DAT_030007a0;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08002666(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_03000610) {
    do {
      if ((&DAT_03000614)[iVar1] == param_1) goto _08002688;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_03000610);
  }
  iVar1 = -1;
_08002688:
  DAT_03000610 = DAT_03000610 + -1;
  if (DAT_03000610 - iVar1 != 0) {
    REG_DMA3SAD = &DAT_03000618 + iVar1;
    REG_DMA3DAD = &DAT_03000614 + iVar1;
    Ram040000dc = (short)(DAT_03000610 - iVar1);
    DAT_040000de = 0x8400;
  }
  iVar1 = ((uint)(param_1 + -0x2003840 >> 0x1f) >> 0x1a) + param_1 + -0x2003840;
  (&DAT_030007a0)[iVar1 >> 9] = (&DAT_030007a0)[iVar1 >> 9] & ~(byte)(1 << (iVar1 >> 6 & 7U));
  return;
}

