/* sub_0800636C  (original: 0x0800636C-0x0800640C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 36% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int sub_08005526();
extern int sub_08003398();
extern int sub_08006330();
extern undefined1 volatile DAT_0300004e;
extern undefined volatile DAT_03000070;
extern undefined1 volatile gUnknown_081C7A84;


undefined4 sub_0800636C(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  short local_14;
  short sStack_12;
  
  if (param_2 == 0) {
    iVar3 = *(int *)(param_1 + 0x3c);
    uVar1 = sub_08003398();
    local_14 = (short)uVar1;
    if ((((*(short *)(iVar3 + 8) <= local_14) && (local_14 < *(short *)(iVar3 + 0xc))) &&
        (sStack_12 = (short)((uint)uVar1 >> 0x10), *(short *)(iVar3 + 10) <= sStack_12)) &&
       (sStack_12 < *(short *)(iVar3 + 0xe))) {
      iVar2 = 0;
      do {
        if (((&gUnknown_081C7A84)[iVar2] == *(char *)(iVar3 + 6)) &&
           ((&DAT_0300004e)[iVar2] != '\0')) {
          *(undefined4 *)(param_1 + 0x38) = 0x8002553;
          (&DAT_03000070)[*(byte *)(iVar3 + 7)] = (char)iVar2;
          (&DAT_0300004e)[iVar2] = (&DAT_0300004e)[iVar2] + -1;
          sub_0800ACFE(7);
          sub_08006330(param_1,(char)iVar2);
          sub_08005526((uint)*(byte *)(iVar3 + 4));
          return 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x22);
    }
  }
  return 0;
}

