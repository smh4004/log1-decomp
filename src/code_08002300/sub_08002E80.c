/* sub_08002E80  (original: 0x08002E80-0x08002F3E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 26% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002CE0();
extern int sub_08004FFA();
extern int sub_0800ACFE();
extern int sub_0800245A();
extern int sub_08002E42();
extern int sub_08002466();
extern int sub_0800B3DC();
extern int sub_0800283C();
extern ushort volatile DAT_03003d14;
extern int volatile DAT_03003b6c;
extern int volatile DAT_03000600;
extern char volatile DAT_030007ad;
extern undefined * volatile gUnknown_0801167C;
extern undefined4 volatile DAT_030007c0;
extern undefined4 volatile DAT_030007d4;
extern undefined4 volatile DAT_030007dc;
extern undefined4 volatile DAT_030007b4;
extern char volatile DAT_030007b0;
extern int volatile DAT_030007bc;
extern int volatile DAT_030005fc;
extern byte volatile DAT_030007b1;
extern int volatile DAT_030007e4;
#define _DAT_030007d4 (*(undefined4 volatile *)0x030007D4)
#define _DAT_030007c0 (*(undefined4 volatile *)0x030007C0)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08002E80(int param_1)

{
  int iVar1;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_18 ((short *)((char *)__frame + 0x0))
  sub_08002CE0(param_1,1,0);
  if (((int)((uint)DAT_03003d14 << 0x1f) < 0) && (iVar1 = sub_0800283C(0,0), iVar1 == 0)) {
    sub_08002466(param_1,3 - ((DAT_03003b6c << 0x1f) >> 0x1f));
  }
  if ((int)((uint)DAT_03003d14 << 0x17) < 0) {
    sub_08002E42((undefined4 *)asStack_18);
    iVar1 = sub_08004FFA(DAT_03000600,asStack_18,1);
    if ((iVar1 == 0) || (DAT_030007ad == '\0')) {
      sub_0800ACFE(0x13);
    }
    else {
      _DAT_030007d4 = _DAT_030007c0;
      sub_08002466(param_1,0xe);
      DAT_030007dc = 1;
      DAT_030007b4 = sub_0800ACFE(0x12);
      if (DAT_030007b0 != '\0') {
        sub_0800245A(DAT_030007bc,&gUnknown_0801167C);
      }
    }
  }
  else if (((((int)((uint)DAT_03003d14 << 0x1e) < 0) && (DAT_030005fc != 0xd)) &&
           (DAT_030005fc != 0xe)) && ((DAT_030007b1 != 2 || (DAT_030007e4 <= DAT_03003b6c)))) {
    sub_0800B3DC(param_1,(uint)DAT_030007b1);
    sub_08002466(param_1,5);
  }
  return;
}

