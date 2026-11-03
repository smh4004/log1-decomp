/* sub_0800B260  (original: 0x0800B260-0x0800B2CC in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_0202c224;
extern undefined volatile DAT_02035824;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800B260(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = 0;
  do {
    iVar6 = iVar1 * 2;
    uVar2 = (uint)*(ushort *)((int)&DAT_0202c224 + iVar6);
    iVar3 = *(int *)(param_1 + 4);
    iVar4 = (uVar2 & 0x1f) + iVar3 * -4;
    iVar5 = ((uVar2 << 0x16) >> 0x1b) + iVar3 * -4;
    iVar3 = ((uVar2 << 0x11) >> 0x1b) + iVar3 * -4;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar1 = iVar1 + 1;
    *(ushort *)(&DAT_02035824 + iVar6) =
         (ushort)(iVar3 << 10) | (ushort)iVar4 | (ushort)(iVar5 << 5);
  } while (iVar1 < 0x400);
  REG_DMA3SAD = 0x2035824;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8400;
  return;
}

