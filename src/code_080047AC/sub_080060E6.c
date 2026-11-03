/* sub_080060E6  (original: 0x080060E6-0x08006118 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_03000a14;
extern undefined4 volatile DAT_03000a18;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080060E6(undefined4 param_1)

{
  if (DAT_03000a14 != 0) {
    REG_DMA3SAD = &DAT_03000a14 + DAT_03000a14;
    REG_DMA3DAD = &DAT_03000a18 + DAT_03000a14;
    Ram040000dc = (short)(DAT_03000a14 * 4 >> 2);
    DAT_040000de = 0x84a0;
  }
  DAT_03000a18 = param_1;
  DAT_03000a14 = DAT_03000a14 + 1;
  return;
}

