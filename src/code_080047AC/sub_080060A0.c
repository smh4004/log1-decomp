/* sub_080060A0  (original: 0x080060A0-0x080060E6 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 94% of instructions covered.
 */
#include "ghidra_types.h"
extern int volatile DAT_03000a14;
extern undefined4 volatile DAT_03000a18;
extern undefined4 volatile DAT_03000a1c;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080060A0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_03000a14) {
    do {
      if ((&DAT_03000a18)[iVar2] == param_1) goto _080060C0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_03000a14);
  }
  iVar2 = -1;
_080060C0:
  DAT_03000a14 = DAT_03000a14 + -1;
  iVar1 = DAT_03000a14 - iVar2;
  if (iVar1 != 0) {
    REG_DMA3SAD = &DAT_03000a1c + iVar2;
    REG_DMA3DAD = &DAT_03000a18 + iVar2;
    Ram040000dc = (short)iVar1;
    DAT_040000de = 0x8400;
  }
  return;
}

