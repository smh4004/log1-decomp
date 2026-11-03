/* sub_08000554  (original: 0x08000554-0x08000610 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 34% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000A32();
extern int sub_08000F8C();
extern int sub_080094B8();
extern int sub_0800ACFE();
extern int sub_0800988C();
extern int sub_08008DA0();
extern int sub_08009744();
extern int sub_080007D2();
extern int sub_080097C8();
extern int sub_08000800();
extern ushort volatile DAT_03003d14;
extern int volatile DAT_03000014;
extern int volatile DAT_03003b6c;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0202addc;
extern undefined4 volatile DAT_0300000b;
extern undefined4 volatile DAT_030000fc;
extern undefined4 volatile DAT_030005e8;
extern undefined4 volatile DAT_0300080c;
extern undefined4 volatile DAT_03004398;
extern undefined volatile DAT_0800fe80;


undefined4 sub_08000554(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = sub_080094B8((int *)&DAT_0800fe80,(byte *)(param_1 + 4));
  if (iVar2 != 0) {
    sub_08000A32(4,*(byte *)(param_1 + 4) + 0xd);
    sub_0800ACFE(0);
  }
  if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
    sub_08008DA0(&DAT_02029d94);
    sub_08008DA0(&DAT_0202addc);
    sub_0800988C();
    sub_0800ACFE(0);
    sub_08009744(&DAT_030005e8);
  }
  else if (((DAT_03003d14 & 1) == 0) && (-1 < (int)((uint)DAT_03003d14 << 0x1c))) {
    if (DAT_03000014 < DAT_03003b6c) {
      sub_08009744((int *)((int)&DAT_0300000b + 1));
    }
  }
  else {
    cVar1 = *(char *)(param_1 + 4);
    if (cVar1 == '\0') {
      sub_080007D2(0x3000028);
      sub_0800ACFE(1);
      sub_08000F8C(0x30000ec,&DAT_030000fc,0);
    }
    else if (cVar1 == '\x01') {
      iVar2 = sub_08000800();
      if (iVar2 == 0) {
        sub_0800ACFE(0x13);
      }
      else {
        sub_0800ACFE(1);
        sub_080097C8(&DAT_03004398);
      }
    }
    else if (cVar1 == '\x02') {
      sub_0800ACFE(1);
      sub_080097C8(&DAT_0300080c);
    }
  }
  return 0;
}

