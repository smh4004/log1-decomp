/* sub_0800C338  (original: 0x0800C338-0x0800C398 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800BEA8();
extern undefined * volatile gUnknown_085429A0;


int sub_0800C338(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      if (*(byte *)(*(int *)(iVar1 * 0x18 + param_1 + 4 + 4) + 0x15) == param_2) {
        iVar1 = iVar1 * 0x18 + param_1 + 4;
        iVar2 = *(int *)(iVar1 + 4);
        if (param_3 == 0) {
          return iVar2;
        }
        if (*(int *)(iVar1 + 0x18) == 0) {
          return iVar2;
        }
        *(undefined4 *)(iVar1 + 0x18) = 0;
        iVar1 = sub_0800BEA8(iVar2);
        if (iVar1 != 0) {
          *(byte *)(iVar2 + 0xd) = *(byte *)(iVar2 + 0xd) >> 4;
          *(undefined4 *)(iVar2 + 0x28) = 1;
        }
        *(undefined ***)(iVar2 + 0x18) = &gUnknown_085429A0;
        *(undefined4 *)(iVar2 + 0x38) = 0x800c185;
        return iVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return 0;
}

