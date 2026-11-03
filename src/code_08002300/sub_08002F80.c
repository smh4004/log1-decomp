/* sub_08002F80  (original: 0x08002F80-0x08002FC4 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 4/4 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005BF0();
extern int sub_08005C7A();
extern int sub_08005C32();
extern int sub_08005BE2();
extern int volatile DAT_030000c8;
extern int volatile DAT_030007d8;
extern byte volatile DAT_030000cd;
extern byte volatile DAT_030007b0;
extern byte volatile DAT_030000ce;
extern ushort volatile DAT_030007b2;
extern byte volatile DAT_030000cc;
extern uint volatile DAT_030007e0;
extern undefined4 volatile DAT_030007c4;
extern undefined4 volatile DAT_030007c8;
extern undefined4 volatile DAT_030007cc;
extern undefined4 volatile DAT_030007d0;
extern byte volatile DAT_030007ac;
extern byte volatile DAT_030007ad;
extern byte volatile DAT_030007ae;
extern byte volatile DAT_030007af;
extern byte volatile DAT_030007b1;


void sub_08002F80(void)

{
  DAT_030007d8 = DAT_030000c8;
  DAT_030007b0 = DAT_030000cd;
  DAT_030007b2 = (ushort)DAT_030000ce;
  DAT_030007e0 = (uint)DAT_030000cc;
  sub_08005C32(DAT_030000c8);
  DAT_030007c4 = sub_08005BF0();
  DAT_030007c8 = DAT_030007c4;
  DAT_030007cc = sub_08005BE2();
  DAT_030007d0 = DAT_030007cc;
  DAT_030007ac = sub_08005C7A();
  DAT_030007ad = DAT_030007ac;
  DAT_030007ae = 0x14;
  DAT_030007af = 0x14;
  DAT_030007b1 = 0;
  return;
}

