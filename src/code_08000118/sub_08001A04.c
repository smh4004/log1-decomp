/* sub_08001A04  (original: 0x08001A04-0x08001A50 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_08000A58();
extern int sub_08008E06();
extern int sub_08009486();
extern byte volatile DAT_0300004d;
extern ushort volatile DAT_02029d9e;
extern short volatile DAT_02029da0;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0800ffd4;
extern undefined4 volatile DAT_08010000;


void sub_08001A04(void)

{
  uint uVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486((int *)&DAT_0800ffd4,&DAT_02029d94);
  uVar1 = 0;
  do {
    if (((uint)DAT_0300004d & 1 << (uVar1 & 0xff)) != 0) {
      DAT_02029da0 = (short)uVar1 * 2 + 7;
      DAT_02029d9e = 6;
      sub_08008E06(&DAT_02029d94,(byte *)(&DAT_08010000)[uVar1]);
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 3);
  sub_08008D8A(0x2029d94);
  return;
}

