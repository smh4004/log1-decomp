/* sub_080092CA  (original: 0x080092CA-0x0800930A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_080092CA(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)*(short *)(param_1 + 4);
  if (iVar2 < *(short *)(param_1 + 8)) {
    do {
      iVar1 = (int)*(short *)(param_1 + 2);
      if (iVar1 < *(short *)(param_1 + 6)) {
        do {
          iVar3 = iVar2 * 0x40 + param_1 + iVar1 * 2;
          iVar1 = iVar1 + 1;
          *(undefined2 *)(iVar3 + 0x24) = *(undefined2 *)(iVar3 + 100);
        } while (iVar1 < *(short *)(param_1 + 6));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(short *)(param_1 + 8));
  }
  return;
}

