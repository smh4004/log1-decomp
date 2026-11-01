/* sub_0800C188  (original: 0x0800C188-0x0800C20A in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800241E();
extern int __call_via_r3();
extern int sub_0800BEA8();
extern int sub_08002466();
extern undefined * volatile gUnknown_085429A0;


void sub_0800C188(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_2 + 0x15) != -1) {
    piVar1 = (int *)(param_1 + 4);
    iVar3 = *piVar1;
    *piVar1 = iVar3 + 1;
    piVar1[iVar3 * 6 + 2] = 0;
    piVar1[iVar3 * 6 + 1] = param_2;
    piVar1[iVar3 * 6 + 3] = *(int *)(param_2 + 0x18);
    piVar1[iVar3 * 6 + 4] = *(int *)(param_2 + 0x38);
    *(undefined1 *)(piVar1 + iVar3 * 6 + 5) = 0;
    *(undefined1 *)((int)piVar1 + iVar3 * 0x18 + 0x15) = *(undefined1 *)(param_2 + 0xd);
    iVar2 = sub_0800241E(param_2);
    piVar1[iVar3 * 6 + 6] = (uint)(iVar2 == 2);
    iVar2 = __call_via_r3(param_2,3,0,*(undefined4 *)(param_2 + 0x38));
    if (iVar2 != 0) {
      piVar1[iVar3 * 6 + 2] = *(int *)(param_2 + 0x3c);
    }
    if (piVar1[iVar3 * 6 + 6] == 0) {
      iVar2 = sub_0800BEA8(param_2);
      if (iVar2 != 0) {
        *(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xd) >> 4;
        *(undefined4 *)(param_2 + 0x28) = 1;
      }
      *(undefined ***)(param_2 + 0x18) = &gUnknown_085429A0;
      *(undefined4 *)(param_2 + 0x38) = 0x800c185;
      sub_08002466(param_2,(char)piVar1[iVar3 * 6 + 5]);
    }
  }
  return;
}

