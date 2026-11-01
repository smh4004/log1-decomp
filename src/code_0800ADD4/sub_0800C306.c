/* sub_0800C306  (original: 0x0800C306-0x0800C338 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_0800C306(int param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      if (*(byte *)(*(int *)(iVar1 * 0x18 + param_1 + 4 + 4) + 0x15) == param_2) {
        *(undefined1 *)(iVar1 * 0x18 + param_1 + 4 + 0x14) = param_3;
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return;
}

