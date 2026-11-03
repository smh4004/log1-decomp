/* sub_08001390  (original: 0x08001390-0x0800146A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 96% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_0800091C();
extern int sub_080032B8();
extern int sub_08008E3A();
extern undefined8 __16__rt_sdiv();
extern int sub_08000A58();
extern int sub_080032C0();
extern int sub_08009486();
extern ushort volatile DAT_02029d9e;
extern ushort volatile DAT_02029da0;
extern undefined volatile _080015A4;
extern undefined4 volatile DAT_030007d8;
extern undefined volatile _080015B0;
extern undefined4 volatile DAT_030007d0;
extern undefined4 volatile DAT_030007c8;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0800ff38;
extern undefined volatile gUnknown_0800FF0C;


void sub_08001390(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  sub_08008D14(&DAT_02029d94);
  sub_08009486((int *)&gUnknown_0800FF0C,&DAT_02029d94);
  sub_08009486((int *)&DAT_0800ff38,&DAT_02029d94);
  DAT_02029d9e = 0xb;
  DAT_02029da0 = 3;
  uVar1 = sub_080032B8();
  sub_08008E3A(&DAT_02029d94,&_080015A4,uVar1);
  DAT_02029d9e = 0x10;
  DAT_02029da0 = 5;
  sub_08008E3A(&DAT_02029d94,&_080015A4,DAT_030007d8);
  DAT_02029d9e = 0x13;
  DAT_02029da0 = 7;
  uVar1 = sub_080032C0();
  sub_08008E3A(&DAT_02029d94,&_080015A4,uVar1);
  DAT_02029d9e = 0x15;
  DAT_02029da0 = 0xc;
  sub_08008E3A(&DAT_02029d94,&_080015B0,DAT_030007d0);
  DAT_02029d9e = 0x15;
  DAT_02029da0 = 0xe;
  sub_08008E3A(&DAT_02029d94,&_080015B0,DAT_030007c8);
  DAT_02029d9e = 0x14;
  DAT_02029da0 = 0x11;
  uVar2 = sub_0800091C(0x3000028);
  if (0x14996c4 < (int)uVar2) {
    sub_08008E3A(&DAT_02029d94,"99:59:59");
  }
  uVar2 = __16__rt_sdiv(0x3c,uVar2);
  uVar3 = __16__rt_sdiv(0x3c,uVar2);
  uVar4 = __16__rt_sdiv(0x3c,(uint)uVar3);
  sub_08008E3A(&DAT_02029d94,"%02d:%02d:%02d",(int)uVar4,(int)((ulonglong)uVar4 >> 0x20),
               (int)((ulonglong)uVar3 >> 0x20));
  sub_08000A58();
  sub_08008D8A(0x2029d94);
  return;
}

