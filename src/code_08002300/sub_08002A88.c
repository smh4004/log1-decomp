/* sub_08002A88  (original: 0x08002A88-0x08002B62 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 24% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800236E();
extern int sub_08004FFA();
extern int sub_08003290();
extern int sub_08002134();
extern int sub_0800BEB8();
extern int sub_0800ACFE();
extern int sub_080031E2();
extern int sub_08002CE0();
extern int sub_08002328();
extern int sub_08002466();
extern ushort volatile DAT_03003d14;
extern int volatile DAT_03000600;
extern ushort volatile DAT_03003d12;
extern ushort volatile DAT_030007d4;
extern short volatile DAT_030007c0;
extern short volatile DAT_030007d6;
extern short volatile DAT_030007c2;
extern char volatile DAT_030007b0;
extern int volatile DAT_030007bc;
#define _DAT_030007d4 (*(undefined2 volatile *)0x030007D4)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08002A88(int param_1)

{
  int iVar1;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_18 ((short *)((char *)__frame + 0x0))
#define uStack_14 (*(undefined4 *)((char *)__frame + 0x4))
  if ((int)((uint)DAT_03003d14 << 0x17) < 0) {
    sub_0800236E((undefined4 *)asStack_18,param_1);
    iVar1 = sub_08004FFA(DAT_03000600,asStack_18,0);
    if (iVar1 == 0) {
      sub_0800ACFE(0x13);
      return;
    }
  }
  else {
    sub_08002CE0(param_1,2,1);
    if (((uint)DAT_03003d12 << 0x18) >> 0x1c == 0) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x24) + 1;
    *(int *)(param_1 + 0x24) = iVar1;
    if (iVar1 < 8) {
      return;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar1 = sub_08003290();
    if (iVar1 != 0) {
      return;
    }
    sub_0800236E((undefined4 *)asStack_18,param_1);
    iVar1 = sub_08004FFA(DAT_03000600,asStack_18,0);
    if (iVar1 == 0) {
      DAT_030007c0 = _DAT_030007d4;
      DAT_030007c2 = DAT_030007d6;
      uStack_14 = CONCAT22(DAT_030007d6 >> 4,_DAT_030007d4 >> 4);
      *(undefined4 *)(param_1 + 0x20) = uStack_14;
      sub_08002328((undefined4 *)asStack_18,param_1);
      sub_08002134(asStack_18);
      sub_0800BEB8(param_1);
      sub_0800ACFE(0x13);
    }
  }
  sub_080031E2();
  sub_08002466(param_1,1);
  iVar1 = DAT_030007bc;
  if (DAT_030007b0 != '\0') {
    *(undefined4 *)(DAT_030007bc + 0x20) = *(undefined4 *)(param_1 + 0x20);
    sub_08002466(iVar1,0);
  }
  return;
}

