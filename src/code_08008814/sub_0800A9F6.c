/* sub_0800A9F6  (original: 0x0800A9F6-0x0800AB00 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_0800E640();
extern undefined4 volatile DAT_03003d34;
extern undefined4 volatile DAT_03003d38;
extern undefined2 volatile DAT_04000102;
extern ushort volatile DAT_03003d2e;
extern undefined4 volatile DAT_03003d40;
extern int volatile DAT_03003d3c;
extern ushort volatile DAT_040000c6;
extern undefined4 volatile DAT_030047ec;
extern undefined4 volatile DAT_03003bb3;
extern undefined4 volatile DAT_040000cc;
extern undefined1 volatile DAT_03003d2c;
extern undefined1 volatile DAT_03003d2d;
extern undefined volatile DAT_0203ee24;
extern ushort volatile DAT_040000d0;
extern undefined1 volatile DAT_0203f04c;
extern undefined4 volatile DAT_0203f068;
extern ushort volatile DAT_040000d2;
extern undefined1 volatile DAT_0203f070;
extern ushort volatile REG_SOUNDCNT_L;
extern undefined1 volatile DAT_0203f40c;
extern ushort volatile REG_SOUNDCNT_H;
extern undefined1 volatile DAT_0203f430;
extern ushort volatile REG_SOUNDCNT_X;
extern undefined4 volatile REG_DMA1SAD;
extern undefined4 volatile REG_DMA1DAD;
extern ushort volatile REG_DMA1CNT;
extern undefined4 volatile REG_DMA2SAD;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
extern undefined2 volatile REG_TM0CNT;
extern ushort volatile REG_IE;
#define Ram040000c4 (*(undefined2 volatile *)0x040000C4)
#define Ram040000d0 (*(undefined2 volatile *)0x040000D0)
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800A9F6(ushort param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_03003d34 = 0;
  DAT_03003d38 = 0;
  DAT_03003d40 = 0;
  DAT_03003d2e = param_1;
  iVar2 = sub_0800E640((uint)param_1,param_1 + 0x3ffffff);
  iVar3 = 0;
  DAT_03003d3c = iVar2;
  do {
    iVar4 = iVar3 + 1;
    (&DAT_0203f068)[iVar3 * 0x10] = &DAT_0203ee24 + iVar3 * 0x24;
    iVar3 = iVar4;
  } while (iVar4 < 0xf);
  REG_SOUNDCNT_X = 0x80;
  REG_SOUNDCNT_H = 0x9a0e;
  REG_DMA1SAD = 0x203f800;
  REG_DMA1DAD = 0x40000a0;
  Ram040000c4 = 4;
  DAT_040000c6 = 0xb660;
  REG_DMA2SAD = 0x203fe00;
  DAT_040000cc = 0x40000a4;
  Ram040000d0 = 4;
  DAT_040000d2 = 0xf660;
  REG_SOUNDCNT_L = 0;
  REG_DMA3SAD = 0x8008814;
  REG_DMA3DAD = 0x3003d44;
  Ram040000dc = 0x2a;
  DAT_040000de = 0x8400;
  REG_DMA3SAD = 0x80088bc;
  REG_DMA3DAD = 0x3003dec;
  Ram040000dc = 0x34;
  DAT_040000de = 0x8400;
  REG_DMA3SAD = 0x800898c;
  REG_DMA3DAD = 0x3003ebc;
  Ram040000dc = 0x35;
  DAT_040000de = 0x8400;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x203ee24;
  Ram040000dc = 0x477;
  DAT_040000de = 0x8500;
  DAT_03003bb3 = 0x8008aa7;
  uVar1 = REG_IE;
  REG_IE = uVar1 | 0x400;
  REG_TM0CNT = (short)((uint)-(iVar2 + 3) >> 2);
  DAT_04000102 = 0x80;
  iVar3 = 0;
  DAT_03003d2c = 4;
  do {
    iVar2 = iVar3 * 0x40;
    (&DAT_0203f070)[iVar2] = 4;
    iVar3 = iVar3 + 1;
    (&DAT_0203f04c)[iVar2] = (&DAT_0203f04c)[iVar2] | 0x10;
  } while (iVar3 < 0xf);
  DAT_03003d2d = 8;
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x40;
    (&DAT_0203f430)[iVar2] = 8;
    iVar3 = iVar3 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] | 0x10;
  } while (iVar3 < 0x10);
  return;
}

