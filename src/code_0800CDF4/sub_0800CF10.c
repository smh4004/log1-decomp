/* sub_0800CF10  (original: 0x0800CF10-0x0800CF76 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int WaitForVBlank();
extern int sub_080095DC();
extern int sub_0800AB3E();
extern undefined2 volatile DAT_04000020;
extern undefined2 volatile REG_BLDCNT;
extern undefined2 volatile DAT_04000022;
extern undefined2 volatile DAT_04000024;
extern undefined2 volatile DAT_04000026;
extern undefined4 volatile DAT_04000028;
extern undefined4 volatile DAT_0400002c;
extern undefined2 volatile REG_DISPCNT;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800CF10(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080095DC(*(int *)(param_1 + 8));
  sub_0800AB3E();
  WaitForVBlank(1);
  REG_DISPCNT = 0x404;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = 0x100;
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = 0x100;
  REG_BLDCNT = 0;
  REG_DMA3SAD = **(undefined4 **)(param_1 + 8);
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  iVar2 = 0;
  do {
    REG_DMA3SAD = iVar2 * 0xf0 + iVar1;
    REG_DMA3DAD = iVar2 * 0xf0 + 0x6000000;
    Ram040000dc = 0x78;
    DAT_040000de = 0x8000;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xa0);
  return;
}

