/* sub_080019D8  (original: 0x080019D8-0x08001A04 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 23/23 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08000A32();
extern int sub_08008D14();
extern int sub_080090AE();
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile gUnknown_0800FFCC;


void sub_080019D8(void)

{
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(0x202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,(short *)&gUnknown_0800FFCC);
  sub_08008D8A(0x202addc);
  sub_08000A32(2,0x10);
  return;
}

