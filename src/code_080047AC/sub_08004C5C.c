/* sub_08004C5C  (original: 0x08004C5C-0x08004CAC in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 95% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined1 volatile DAT_03000028;


undefined4 sub_08004C5C(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      uVar2 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 8) + iVar1 * 4) + 4);
      if (((&DAT_03000028)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7))) == 0) {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return 1;
}

