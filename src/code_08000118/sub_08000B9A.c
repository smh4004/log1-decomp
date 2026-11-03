/* sub_08000B9A  (original: 0x08000B9A-0x08000C02 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_08008E3A();
extern int sub_08000A58();
extern int sub_08009486();
extern ushort volatile DAT_02029d9e;
extern ushort volatile DAT_02029da0;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0800feb4;
extern undefined volatile _08000E18;


void sub_08000B9A(int param_1)

{
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486((int *)&DAT_0800feb4,&DAT_02029d94);
  DAT_02029d9e = 6;
  DAT_02029da0 = 5;
  sub_08008E3A(&DAT_02029d94,&_08000E18,*(byte *)(param_1 + 5) + 1);
  DAT_02029d9e = 6;
  DAT_02029da0 = 0xb;
  sub_08008E3A(&DAT_02029d94,&_08000E18,(uint)*(byte *)(param_1 + 6));
  DAT_02029d9e = 6;
  DAT_02029da0 = 0xe;
  sub_08008E3A(&DAT_02029d94,&_08000E18,(uint)*(byte *)(param_1 + 7));
  DAT_02029d9e = 6;
  DAT_02029da0 = 0x11;
  sub_08008E3A(&DAT_02029d94,&_08000E18,(uint)*(byte *)(param_1 + 8));
  sub_08008D8A(0x2029d94);
  return;
}

