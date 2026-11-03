/* sub_080002C0  (original: 0x080002C0-0x08000314 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080095DC();
extern undefined volatile gUnknown_0800FE4C;
extern byte volatile REG_BLDY;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080002C0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 4) = 0;
  REG_BLDY = 0x10;
  uVar1 = sub_080095DC((int)(&gUnknown_0800FE4C + (uint)*(byte *)(param_1 + 5) * 0xc));
  REG_DMA3SAD = *(undefined4 *)(&gUnknown_0800FE4C + (uint)*(byte *)(param_1 + 5) * 0xc);
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  REG_DMA3SAD = uVar1;
  REG_DMA3DAD = 0x6000000;
  Ram040000dc = 0x4b00;
  DAT_040000de = 0x8000;
  *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + '\x01';
  return;
}

