/* sub_08003880  (original: 0x08003880-0x08003952 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008E06();
extern int sub_08002556();
extern int sub_08002896();
extern int sub_0800370C();
extern int sub_080090AE();
extern int sub_08008D14();
extern int sub_08009064();
extern ushort volatile DAT_02029d9e;
extern ushort volatile DAT_02029da0;
extern int volatile DAT_030007ec;
extern int volatile DAT_030007e8;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0202addc;
extern undefined volatile DAT_08010848;
extern undefined volatile DAT_08010850;
extern undefined4 volatile gUnknown_08010EC4;
extern undefined * volatile PTR_gUnknown_08010BA4_080109f0;
extern int sub_080039AC();


void sub_08003880(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  sub_08008D14(&DAT_02029d94);
  sub_08008D14(&DAT_0202addc);
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 != '\0') {
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) goto _080038F4;
    sub_080090AE(&DAT_0202addc,(short *)&DAT_08010850);
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      DAT_02029d9e = 0xe;
      DAT_02029da0 = (undefined2)iVar3;
      sub_08009064(&DAT_02029d94,(byte *)(&gUnknown_08010EC4)[iVar2]);
      iVar2 = iVar3;
    } while (iVar3 < 0x11);
  }
  sub_080090AE(&DAT_0202addc,(short *)&DAT_08010848);
  iVar2 = 0;
  do {
    DAT_02029d9e = 2;
    iVar3 = iVar2 + 1;
    DAT_02029da0 = (undefined2)iVar3;
    sub_08009064(&DAT_02029d94,
                 (&PTR_gUnknown_08010BA4_080109f0)[(uint)*(byte *)(param_1 + 5) + iVar2]);
    iVar2 = iVar3;
  } while (iVar3 < 0x12);
_080038F4:
  sub_08002556(0,1);
  sub_08002896();
  if (DAT_030007ec == 0) {
    DAT_02029d9e = 0x1a;
    DAT_02029da0 = 2;
    sub_08008E06(&DAT_02029d94,(byte *)sub_080039AC);
    DAT_02029d9e = 0x1a;
    DAT_02029da0 = 3;
    sub_08008E06(&DAT_02029d94,(byte *)0x80039b0);
  }
  if (DAT_030007e8 == 0) {
    DAT_02029d9e = 0x19;
    DAT_02029da0 = 0xf;
    sub_08008E06(&DAT_02029d94,(byte *)0x80039b4);
  }
  sub_0800370C(param_1);
  sub_08008D8A(0x2029d94);
  sub_08008D8A(0x202addc);
  return;
}

