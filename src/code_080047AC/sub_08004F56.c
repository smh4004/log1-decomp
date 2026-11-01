/* sub_08004F56  (original: 0x08004F56-0x08004FD0 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 8/8 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009680();
extern int sub_08009626();
extern int volatile DAT_03000a14;
extern undefined volatile DAT_02005040;
extern undefined4 volatile DAT_03000a18;
extern undefined4 volatile REG_DMA3SAD;


void sub_08004F56(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  DAT_03000a14 = 0;
  sub_08009680(&REG_DMA3SAD,&DAT_02005040,0xffffffff,0x57e4,param_4);
  sVar2 = *(short *)(param_1 + 4);
  sVar3 = *(short *)(param_1 + 6);
  iVar5 = 0;
  do {
    iVar4 = *(int *)(iVar5 * 4 + param_1 + 8);
    if (iVar4 != 0) {
      sub_08009626(&REG_DMA3SAD,&DAT_02005040 + iVar5 * 0x1d4c,iVar4,
                   (int)sVar3 * (int)sVar2 + 0x1f >> 3);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  if ((*(int *)(param_1 + 0x14) != 0) && (iVar5 = 0, 0 < *(int *)(*(int *)(param_1 + 0x14) + 0x18)))
  {
    do {
      iVar4 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      puVar1 = &DAT_03000a18 + DAT_03000a14;
      DAT_03000a14 = DAT_03000a14 + 1;
      *puVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 0x1c) + iVar4);
    } while (iVar5 < *(int *)(*(int *)(param_1 + 0x14) + 0x18));
  }
  return;
}

