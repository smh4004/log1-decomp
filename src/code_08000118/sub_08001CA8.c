/* sub_08001CA8  (original: 0x08001CA8-0x08001CFA in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08008D14();
extern int sub_08008D8A();
extern int sub_080090AE();
extern undefined1 volatile DAT_04000041;
extern undefined volatile DAT_0202a5b8;
extern undefined2 volatile REG_BG0HOFS;
extern undefined1 volatile DAT_04000044;
extern undefined volatile DAT_0202addc;
extern undefined2 volatile REG_BG0VOFS;
extern undefined1 volatile DAT_04000045;
extern undefined volatile gUnknown_08010094;
extern undefined1 volatile REG_WIN0H;
extern undefined2 volatile REG_DISPCNT;
extern undefined1 volatile REG_WININ;
extern undefined1 volatile REG_WINOUT;


void sub_08001CA8(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_08010094);
  sub_08008D8A(&DAT_0202addc);
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

