/* sub_0800C060  (original: 0x0800C060-0x0800C090 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080090AE();
extern int sub_08008D14();
extern int sub_08008D8A();
extern int sub_08000A32();
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile gUnknown_0801207C;


void sub_0800C060(int param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(0x202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,(short *)&gUnknown_0801207C);
  sub_08008D8A(0x202addc);
  sub_08000A32(5,0xd);
  return;
}

