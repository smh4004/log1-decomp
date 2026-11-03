/* sub_08001AC4  (original: 0x08001AC4-0x08001B5C in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 6/6 snapshots, 26% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000A32();
extern int sub_080008B4();
extern int sub_08009798();
extern int sub_080094B8();
extern int sub_0800084A();
extern int sub_080060E6();
extern int sub_080097F8();
extern int sub_0800ACFE();
extern ushort volatile DAT_03003d14;
extern uint volatile DAT_030005d4;
extern undefined4 volatile DAT_030005d0;
extern char volatile DAT_03003b60;
extern undefined4 volatile DAT_030005cc;
extern undefined volatile DAT_08010054;
extern undefined volatile DAT_08010080;


undefined4 sub_08001AC4(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080094B8((int *)&DAT_08010054,(byte *)(param_1 + 4));
  if (iVar1 != 0) {
    uVar2 = (uint)*(byte *)(param_1 + 4);
    if (1 < uVar2) {
      uVar2 = 4;
    }
    sub_08000A32(5,uVar2 + 0xd);
    sub_0800ACFE(0);
  }
  if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  else if ((DAT_03003d14 & 1) != 0) {
    uVar2 = (uint)*(byte *)(param_1 + 4);
    if ((uVar2 == 0) || (uVar2 == 1)) {
      iVar1 = sub_0800084A(uVar2);
      if (iVar1 == 0) {
        sub_080008B4(0x3000028,(uint)*(byte *)(param_1 + 4));
        DAT_03003b60 = DAT_03003b60 + -1;
        sub_08009798();
        sub_080060E6(&DAT_08010080);
      }
      else {
        DAT_030005d4 = (uint)*(byte *)(param_1 + 4);
        DAT_030005d0 = 1;
        sub_080097F8(&DAT_030005cc);
      }
    }
    else if (uVar2 == 2) {
      sub_0800ACFE(0);
      sub_08009798();
    }
  }
  return 0;
}

