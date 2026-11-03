/* sub_0800146A  (original: 0x0800146A-0x0800151C in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 28% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000A32();
extern int sub_08009798();
extern int sub_080097C8();
extern int sub_080094B8();
extern int sub_0800ACFE();
extern ushort volatile DAT_03003d14;
extern undefined4 volatile DAT_03000598;
extern undefined4 volatile DAT_030005a0;
extern undefined4 volatile DAT_030005bc;
extern undefined4 volatile DAT_030005c4;
extern undefined4 volatile DAT_030005d8;
extern undefined4 volatile DAT_0300080c;
extern undefined volatile gUnknown_0800FF0C;


undefined4 sub_0800146A(int param_1)

{
  int iVar1;
  
  iVar1 = sub_080094B8((int *)&gUnknown_0800FF0C,(byte *)(param_1 + 4));
  if (iVar1 != 0) {
    sub_08000A32(2,*(byte *)(param_1 + 4) + 0xb);
    sub_0800ACFE(0);
  }
  if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  else if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1c) < 0)) {
    switch(*(undefined1 *)(param_1 + 4)) {
    case 0:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_03000598);
      break;
    case 1:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_030005a0);
      break;
    case 2:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_030005bc);
      break;
    case 3:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_030005c4);
      break;
    case 4:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_0300080c);
      break;
    case 5:
      sub_080097C8(&DAT_030005d8);
      break;
    case 6:
      sub_0800ACFE(0);
      sub_08009798();
    }
  }
  return 0;
}

