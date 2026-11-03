/* sub_08006D90  (original: 0x08006D90-0x08006F1A in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 55% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800F3E4();
extern int __16__rt_sdiv();
extern undefined4 volatile DAT_030047ec;
extern undefined4 volatile DAT_030007d8;
extern int volatile DAT_030007c4;
extern undefined4 volatile DAT_030007c8;
extern uint volatile DAT_030007cc;
extern undefined4 volatile DAT_030007d0;
extern int volatile DAT_03000c1c;
extern undefined volatile DAT_086b6098;
extern undefined volatile DAT_086b609c;
extern undefined volatile DAT_086b60a0;
extern undefined volatile DAT_086b60a4;
extern undefined volatile DAT_086b60a6;
extern undefined volatile DAT_086b60a8;
extern undefined volatile DAT_086b60aa;
extern undefined volatile DAT_086b60ac;
extern undefined volatile DAT_086b60ae;
extern undefined volatile DAT_086b60b0;
extern undefined volatile DAT_086b60b2;
extern undefined volatile DAT_086b60b4;
extern undefined volatile DAT_086b60b6;
extern undefined volatile DAT_086b60b8;
extern undefined volatile DAT_086b60ba;
extern undefined volatile DAT_086b60bc;
extern undefined volatile DAT_086b60be;
extern undefined volatile DAT_086b60c0;
extern undefined volatile DAT_086b60c2;
extern undefined volatile DAT_086b60c4;
extern undefined volatile DAT_086b60c8;
extern undefined4 volatile REG_DMA3SAD;
extern undefined volatile DAT_086b60cc;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern undefined volatile DAT_086b60d0;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08006D90(undefined2 *param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if ((((param_2 == 2) || (param_2 == 1)) && (-1 < param_3)) && (param_3 < 0x23)) {
    DAT_030047ec = 0;
    REG_DMA3SAD = 0x30047ec;
    REG_DMA3DAD = param_1 + 4;
    Ram040000dc = 0xb;
    DAT_040000de = 0x8500;
    *param_1 = (short)param_3;
    param_1[0x4d] = (short)param_2;
    param_1[0x4e] = 1;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x52) = 0;
    *(undefined4 *)(param_1 + 0x4a) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    param_1[0x4c] = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x56) = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x12e) = 0;
    iVar7 = 0;
    do {
      iVar6 = iVar7 + 1;
      *(undefined4 *)(param_1 + iVar7 * 2 + 0x130) = 0;
      iVar7 = iVar6;
    } while (iVar6 < 5);
    iVar7 = 0;
    do {
      iVar6 = iVar7 + 1;
      param_1[iVar7 * 2 + 0x120] = 0xffff;
      param_1[iVar7 * 2 + 0x121] = 1;
      iVar7 = iVar6;
    } while (iVar6 < 5);
    param_1[0x12a] = 0;
    param_1[299] = 0;
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x42) = DAT_030007d8;
      iVar7 = DAT_030007c4;
      *(int *)(param_1 + 0x2c) = DAT_030007c4;
      *(undefined4 *)(param_1 + 0x2a) = DAT_030007c8;
      uVar4 = DAT_030007cc;
      *(uint *)(param_1 + 0x28) = DAT_030007cc;
      uVar5 = DAT_030007d0;
      *(int *)(param_1 + 0x2e) = iVar7 >> 6;
      *(undefined4 *)(param_1 + 0x26) = uVar5;
      if (param_1[0x4d] == 1) {
        iVar7 = __16__rt_sdiv(3,uVar4);
        DAT_03000c1c = iVar7 + 1;
      }
      *(undefined1 *)(param_1 + 0x14) = 0;
      *(undefined1 *)((int)param_1 + 0x29) = 0;
      *(undefined1 *)(param_1 + 0x15) = 0x10;
      *(undefined1 *)((int)param_1 + 0x2b) = 8;
      *(undefined4 *)(param_1 + 0x30) = 0xfa;
    }
    else {
      iVar7 = param_3 * 0x40;
      *(undefined4 *)(param_1 + 0x2a) = *(undefined4 *)(&DAT_086b60c8 + iVar7);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(&DAT_086b60c8 + iVar7);
      *(undefined4 *)(param_1 + 0x26) = *(undefined4 *)(&DAT_086b60cc + iVar7);
      iVar6 = *(int *)(&DAT_086b60cc + iVar7);
      *(int *)(param_1 + 0x28) = iVar6;
      if (iVar6 < 1) {
        *(undefined4 *)(param_1 + 0x28) = 1;
      }
      *(undefined4 *)(param_1 + 2) = *(undefined4 *)(&DAT_086b6098 + iVar7);
      param_1[1] = (short)*(undefined4 *)(&DAT_086b609c + iVar7);
      *(undefined4 *)(param_1 + 0x42) = *(undefined4 *)(&DAT_086b60a0 + iVar7);
      param_1[0x1e] = *(undefined2 *)(&DAT_086b60a4 + iVar7);
      param_1[0x1f] = *(undefined2 *)(&DAT_086b60a6 + iVar7);
      param_1[0x20] = *(undefined2 *)(&DAT_086b60a8 + iVar7);
      param_1[0x21] = *(undefined2 *)(&DAT_086b60aa + iVar7);
      sVar1 = *(short *)(&DAT_086b60ac + iVar7);
      param_1[0x22] = sVar1;
      if (1 < sVar1) {
        *(undefined2 **)(param_1 + 0x48) = param_1;
        param_1[0x4c] = 1;
      }
      param_1[0x23] = *(undefined2 *)(&DAT_086b60ae + iVar7);
      param_1[0x24] = *(undefined2 *)(&DAT_086b60b0 + iVar7);
      *(int *)(param_1 + 0x34) = (int)*(short *)(&DAT_086b60b2 + iVar7);
      *(int *)(param_1 + 0x36) = (int)*(short *)(&DAT_086b60b4 + iVar7);
      *(int *)(param_1 + 0x32) = (int)*(short *)(&DAT_086b60b6 + iVar7);
      *(int *)(param_1 + 0x38) = (int)*(short *)(&DAT_086b60b8 + iVar7);
      *(int *)(param_1 + 0x3a) = (int)*(short *)(&DAT_086b60ba + iVar7);
      *(int *)(param_1 + 0x1a) = (int)*(short *)(&DAT_086b60bc + iVar7);
      *(int *)(param_1 + 0x3c) = (int)*(short *)(&DAT_086b60be + iVar7);
      uVar2 = *(undefined2 *)(&DAT_086b60c4 + iVar7);
      uVar3 = *(undefined2 *)(&DAT_086b60c2 + iVar7);
      *(int *)(param_1 + 0x3e) = (int)*(short *)(&DAT_086b60c0 + iVar7);
      sub_0800F3E4(param_1 + 0x40,uVar3,uVar2);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(&DAT_086b60d0 + iVar7);
      *(int *)(param_1 + 0x2e) = *(int *)(param_1 + 0x2c) >> 6;
      if (param_1[0x4d] == 1) {
        iVar7 = __16__rt_sdiv(3,*(uint *)(param_1 + 0x28));
        DAT_03000c1c = iVar7 + 1;
      }
    }
  }
  return;
}

