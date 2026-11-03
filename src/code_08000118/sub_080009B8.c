/* sub_080009B8  (original: 0x080009B8-0x08000A30 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005EA6();
extern byte volatile DAT_030000d0;
extern uint * volatile DAT_030000d4;
extern undefined volatile DAT_0202be24;
extern undefined volatile DAT_0202be28;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_080009B8(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_08005EA6(0x8166c18);
  DAT_030000d0 = (undefined1)iVar1;
  REG_DMA3SAD = 0x8166bf8;
  REG_DMA3DAD = param_2 * 0x20 + 0x6010000;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  iVar2 = param_1 * 8;
  DAT_030000d4 = (uint *)(&DAT_0202be24 + iVar2);
  *DAT_030000d4 = *DAT_030000d4 & 0x1ff00ff;
  *(uint *)(&DAT_0202be28 + iVar2) =
       (uint)(iVar1 << 0x1c) >> 0x10 |
       *(uint *)(&DAT_0202be28 + iVar2) & 0xffff0000 | param_2 & 0x3ff;
  return;
}

