/* sub_08008D14  (original: 0x08008D14-0x08008D3A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern short volatile DAT_030047e8;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08008D14(byte *param_1)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}

