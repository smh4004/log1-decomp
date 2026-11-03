/* sub_08000424  (original: 0x08000424-0x0800051A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000A32();
extern int sub_08008D3A();
extern int sub_080009B8();
extern int sub_08008D8A();
extern int sub_08009586();
extern int sub_080090AE();
extern int sub_08000800();
extern undefined2 volatile REG_BG0CNT;
extern undefined2 volatile REG_BG1CNT;
extern undefined2 volatile gUnknown_08142380;
extern undefined * volatile DAT_0202b610;
extern undefined2 volatile REG_BG2CNT;
extern int volatile DAT_03003b6c;
extern undefined2 volatile REG_BG3CNT;
extern int volatile DAT_03000014;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile DAT_06000000;
extern undefined volatile DAT_0600c000;
extern undefined volatile DAT_0600e000;
extern undefined volatile DAT_0600e800;
extern undefined volatile DAT_0600f000;
extern undefined volatile DAT_0600f800;
extern ushort volatile REG_BLDCNT;
extern undefined1 volatile REG_BLDALPHA;
extern undefined1 volatile DAT_04000053;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
extern undefined volatile gUnknown_081B3514;
extern undefined volatile gUnknown_0800FE76;
extern undefined2 volatile REG_DISPCNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08000424(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  unsigned int __frame[13];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_34 ((ushort *)((char *)__frame + 0x0))
  iVar1 = sub_08000800();
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 4) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 4) = 1;
  }
  REG_DISPCNT = 0x1f00;
  REG_BG0CNT = 0x1c0f;
  REG_BG1CNT = 0x1d0f;
  REG_BG2CNT = 0x1e0f;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x844;
  REG_BLDALPHA = 0x10;
  DAT_04000053 = 0xc;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586((undefined4 *)&gUnknown_081B3514,0x202b600,(int *)&DAT_06000000);
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202a5b8,&DAT_0600e800,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_080090AE(&DAT_0202addc,(short *)&gUnknown_0800FE76);
  sub_08008D8A(0x202addc);
  sub_080009B8(0,1);
  sub_08000A32(4,*(byte *)(param_1 + 4) + 0xd);
  REG_DMA3SAD = 0x50001e0;
  REG_DMA3DAD = auStack_34;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  iVar1 = 0;
  do {
    uVar3 = (uint)auStack_34[iVar1];
    iVar2 = iVar1 + 1;
    auStack_34[iVar1] =
         (ushort)(((uVar3 << 0x11) >> 0x1c) << 10) |
         (ushort)((uVar3 & 0x1f) >> 1) | (ushort)(((uVar3 << 0x16) >> 0x1c) << 5);
    iVar1 = iVar2;
  } while (iVar2 < 0x10);
  REG_DMA3SAD = auStack_34;
  REG_DMA3DAD = 0x50001c0;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  DAT_03000014 = DAT_03003b6c + 0xe10;
  return;
}

