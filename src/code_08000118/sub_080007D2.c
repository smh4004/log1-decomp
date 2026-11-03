/* sub_080007D2  (original: 0x080007D2-0x08000800 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002F3E();
extern ushort volatile DAT_030047e8;
extern int volatile DAT_03003b6c;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080007D2(int param_1)

{
  sub_08002F3E();
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x54;
  DAT_040000de = 0x8100;
  *(int *)(param_1 + 0x1c) = -DAT_03003b6c;
  *(undefined1 *)(param_1 + 0x25) = 1;
  return;
}

