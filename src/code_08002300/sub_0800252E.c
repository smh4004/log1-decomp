/* sub_0800252E  (original: 0x0800252E-0x08002552 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005E8C();
extern undefined4 volatile DAT_03000610;
extern ushort volatile DAT_030047e8;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800252E(void)

{
  DAT_03000610 = 0;
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = 0x30007a0;
  Ram040000dc = 6;
  DAT_040000de = 0x8100;
  sub_08005E8C();
  return;
}

