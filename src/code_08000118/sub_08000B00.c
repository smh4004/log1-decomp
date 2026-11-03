/* sub_08000B00  (original: 0x08000B00-0x08000B9A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08000A32();
extern int sub_080009B8();
extern int sub_08009586();
extern int sub_080090AE();
extern int sub_08008D3A();
extern undefined2 volatile REG_BG0CNT;
extern undefined2 volatile REG_BG1CNT;
extern undefined2 volatile gUnknown_08142380;
extern undefined * volatile DAT_0202b610;
extern undefined2 volatile REG_BG2CNT;
extern undefined1 volatile DAT_02029d94;
extern undefined2 volatile REG_BG3CNT;
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile DAT_06000000;
extern undefined volatile DAT_0600c000;
extern undefined volatile DAT_0600e000;
extern undefined volatile DAT_0600e800;
extern undefined volatile gUnknown_0800FEAC;
extern undefined volatile gUnknown_081B3514;
extern undefined volatile DAT_0600f000;
extern undefined volatile DAT_0600f800;
extern ushort volatile REG_BLDCNT;
extern byte volatile REG_BLDALPHA;
extern byte volatile DAT_04000053;
extern undefined2 volatile REG_DISPCNT;


void sub_08000B00(int param_1)

{
  REG_DISPCNT = 8000;
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
  sub_08008D3A(&DAT_0202a5b8,&DAT_0600e800,&DAT_0600c000,0xe,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_080090AE(&DAT_0202addc,(short *)&gUnknown_0800FEAC);
  sub_08008D8A(0x202addc);
  sub_080009B8(0,1);
  sub_08000A32(2,(uint)*(byte *)(param_1 + 4) * 3 + 4);
  return;
}

