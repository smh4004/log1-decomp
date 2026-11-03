/* sub_08005F2C  (original: 0x08005F2C-0x08005F58 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_030047ec;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08005F2C(undefined4 param_1)

{
  REG_DMA3SAD = 0x3000994;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x3000994;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8500;
  return;
}

