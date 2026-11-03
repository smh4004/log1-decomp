/* sub_08008D8A  (original: 0x08008D8A-0x08008DA0 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08008D8A(int param_1)

{
  REG_DMA3SAD = param_1 + 0x24;
  REG_DMA3DAD = *(undefined4 *)(param_1 + 0x10);
  Ram040000dc = 0x400;
  DAT_040000de = 0x8000;
  return;
}

