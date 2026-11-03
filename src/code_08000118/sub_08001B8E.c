/* sub_08001B8E  (original: 0x08001B8E-0x08001C04 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08000A32();
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_08008E3A();
extern int sub_080090AE();
extern ushort volatile DAT_02029d9e;
extern ushort volatile DAT_02029da0;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0202a5b8;
extern int sub_08001CA0();
extern undefined volatile DAT_0801004a;


void sub_08001B8E(int param_1)

{
  int iVar1;
  
  sub_08008D14(&DAT_0202a5b8);
  sub_080090AE(&DAT_0202a5b8,(short *)&DAT_0801004a);
  sub_080090AE(&DAT_02029d94,(short *)&DAT_0801004a);
  DAT_02029d9e = 6;
  DAT_02029da0 = 9;
  sub_08008E3A(&DAT_02029d94,"Overwrite Slot %d?",*(int *)(param_1 + 8) + 1);
  DAT_02029d9e = 10;
  DAT_02029da0 = 0xb;
  sub_08008E3A(&DAT_02029d94,sub_08001CA0);
  DAT_02029d9e = 0x11;
  DAT_02029da0 = 0xb;
  sub_08008E3A(&DAT_02029d94,0x8001ca4);
  iVar1 = 8;
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = 0xf;
  }
  sub_08000A32(iVar1,0xb);
  sub_08008D8A(0x2029d94);
  sub_08008D8A(0x202a5b8);
  return;
}

