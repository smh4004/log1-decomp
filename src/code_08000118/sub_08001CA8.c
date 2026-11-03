/* sub_08001CA8  (original: 0x08001CA8-0x08001CFA in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 19/19 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_080090AE();
extern byte volatile DAT_04000041;
extern undefined volatile DAT_0202a5b8;
extern ushort volatile REG_BG0HOFS;
extern byte volatile DAT_04000044;
extern undefined volatile DAT_0202addc;
extern ushort volatile REG_BG0VOFS;
extern byte volatile DAT_04000045;
extern undefined volatile gUnknown_08010094;
extern byte volatile REG_WIN0H;
extern undefined2 volatile REG_DISPCNT;
extern byte volatile REG_WININ;
extern byte volatile REG_WINOUT;


void sub_08001CA8(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(0x202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,(short *)&gUnknown_08010094);
  sub_08008D8A(0x202addc);
  REG_DISPCNT = 0x2f00;
  REG_WININ = 0x3f;
  REG_WINOUT = 0x3e;
  DAT_04000041 = 0x10;
  DAT_04000045 = 0x54;
  REG_WIN0H = 0xe0;
  DAT_04000044 = 0x94;
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  return;
}

