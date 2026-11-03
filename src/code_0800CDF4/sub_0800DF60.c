/* sub_0800DF60  (original: 0x0800DF60-0x0800DFC0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080095DC();
extern undefined2 volatile DAT_04000020;
extern undefined2 volatile DAT_04000022;
extern undefined2 volatile DAT_04000024;
extern ushort volatile DAT_04000026;
extern byte volatile DAT_03003b60;
extern undefined4 volatile DAT_04000028;
extern undefined4 volatile DAT_0400002c;
extern ushort volatile REG_BLDCNT;
extern undefined1 volatile REG_BLDY;
extern undefined2 volatile REG_DISPCNT;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800DF60(int param_1)

{
  undefined4 uVar1;
  
  REG_DISPCNT = 0x1f04;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = 0x100;
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = 0x100;
  REG_BLDCNT = 0x84;
  *(undefined1 *)(param_1 + 4) = 0;
  REG_BLDY = 0x10;
  uVar1 = sub_080095DC(0x81c7b50);
  REG_DMA3SAD = 0x819badc;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  REG_DMA3SAD = uVar1;
  REG_DMA3DAD = 0x6000000;
  Ram040000dc = 0x4b00;
  DAT_040000de = 0x8000;
  DAT_03003b60 = 0;
  return;
}

