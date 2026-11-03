/* sub_0800AD54  (original: 0x0800AD54-0x0800AD7C in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined1 volatile DAT_0203f40c;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800AD54(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  REG_DMA3SAD = 0x203f400;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8400;
  iVar1 = 0;
  do {
    iVar2 = iVar1 * 0x40;
    iVar1 = iVar1 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] & 0xfe;
  } while (iVar1 < 0x10);
  return;
}

