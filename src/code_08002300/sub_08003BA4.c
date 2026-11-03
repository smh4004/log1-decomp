/* sub_08003BA4  (original: 0x08003BA4-0x08003BFE in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08000A58();
extern int sub_08009486();
extern int sub_0800946E();
extern int sub_08008E3A();
extern int sub_08008D14();
extern byte volatile DAT_03000020;
extern ushort volatile DAT_02029d9e;
extern ushort volatile DAT_02029da0;
extern byte volatile DAT_03000021;
extern byte volatile DAT_03000022;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile UNK_08010f8c;
extern undefined volatile DAT_08010fb4;
extern undefined volatile _08003D7C;


void sub_08003BA4(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486((int *)&DAT_08010fb4,&DAT_02029d94);
  sub_0800946E(&UNK_08010f8c + (uint)DAT_03000020 * 8,&DAT_02029d94);
  DAT_02029d9e = 6;
  DAT_02029da0 = 0xe;
  sub_08008E3A(&DAT_02029d94,&_08003D7C,(uint)DAT_03000021);
  DAT_02029d9e = 6;
  DAT_02029da0 = 0x10;
  sub_08008E3A(&DAT_02029d94,&_08003D7C,(uint)DAT_03000022);
  sub_08008D8A(0x2029d94);
  return;
}

