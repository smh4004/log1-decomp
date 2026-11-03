/* sub_08005EA6  (original: 0x08005EA6-0x08005F14 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 61% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_03000994;
extern undefined4 volatile DAT_03000998;
extern undefined volatile DAT_05000200;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


int sub_08005EA6(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar4 = iVar2;
    if ((&DAT_03000994)[iVar2 * 2] != 0) {
      iVar1 = 1;
      while (iVar4 = iVar3,
            *(short *)(param_1 + iVar1 * 2) == *(short *)((&DAT_03000998)[iVar2 * 2] + iVar1 * 2)) {
        iVar1 = iVar1 + 1;
        if (0xf < iVar1) {
          (&DAT_03000994)[iVar2 * 2] = (&DAT_03000994)[iVar2 * 2] + 1;
          return iVar2;
        }
      }
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar4;
  } while (iVar2 < 0x10);
  (&DAT_03000994)[iVar4 * 2] = (&DAT_03000994)[iVar4 * 2] + 1;
  (&DAT_03000998)[iVar4 * 2] = param_1;
  REG_DMA3SAD = param_1;
  REG_DMA3DAD = &DAT_05000200 + iVar4 * 0x20;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  return iVar4;
}

