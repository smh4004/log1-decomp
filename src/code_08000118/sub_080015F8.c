/* sub_080015F8  (original: 0x080015F8-0x0800162A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08008D14();
extern int sub_08005542();
extern int sub_08008DA0();
extern int sub_08000A32();
extern int sub_080090AE();
extern int sub_08008D8A();
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined4 volatile DAT_030046b8;
extern undefined volatile gUnknown_0800FF64;


void sub_080015F8(int param_1)

{
  sub_08008DA0(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_0800FF64);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(2,0x10);
  sub_08005542(&DAT_030046b8);
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}

