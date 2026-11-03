/* sub_0800CE80  (original: 0x0800CE80-0x0800CE9C in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800CE80(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x40;
  REG_DMA3SAD = 0x5000000;
  REG_DMA3DAD = param_1 + 8;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8000;
  return;
}

