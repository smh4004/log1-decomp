/* sub_080098DE  (original: 0x080098DE-0x080098F8 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_030047ec;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080098DE(void)

{
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x202be24;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8500;
  return;
}

