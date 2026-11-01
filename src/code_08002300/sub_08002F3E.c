/* sub_08002F3E  (original: 0x08002F3E-0x08002F80 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005C32();
extern int sub_08005C7A();
extern int sub_08005BE2();
extern int sub_08005BF0();
extern undefined2 volatile DAT_030007b2;
extern undefined4 volatile DAT_030007d8;
extern undefined4 volatile DAT_030007c4;
extern undefined4 volatile DAT_030007c8;
extern undefined4 volatile DAT_030007cc;
extern undefined4 volatile DAT_030007d0;
extern undefined1 volatile DAT_030007ac;
extern undefined1 volatile DAT_030007ad;
extern undefined1 volatile DAT_030007ae;
extern undefined1 volatile DAT_030007af;
extern undefined1 volatile DAT_030007b1;
extern undefined1 volatile DAT_030007b0;
extern undefined4 volatile DAT_030007bc;
extern undefined2 volatile DAT_030007c0;
extern undefined2 volatile DAT_030007c2;
extern undefined4 volatile DAT_030007e0;


void sub_08002F3E(void)

{
  DAT_030007b2 = 0x10;
  DAT_030007d8 = 0;
  sub_08005C32(0);
  DAT_030007c4 = sub_08005BF0();
  DAT_030007c8 = DAT_030007c4;
  DAT_030007cc = sub_08005BE2();
  DAT_030007d0 = DAT_030007cc;
  DAT_030007ac = sub_08005C7A();
  DAT_030007ad = DAT_030007ac;
  DAT_030007ae = 0x14;
  DAT_030007af = 0x14;
  DAT_030007b1 = 0;
  DAT_030007b0 = 0;
  DAT_030007bc = 0;
  DAT_030007c0 = 0;
  DAT_030007c2 = 0;
  DAT_030007e0 = 0x20;
  return;
}

