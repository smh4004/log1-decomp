/* sub_08005DE0  (original: 0x08005DE0-0x08005E06 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 61% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002910();


void sub_08005DE0(int param_1)

{
  int iVar1;
  
  sub_08002910(param_1);
  iVar1 = *(int *)(param_1 + 0x3c);
  if (3 < *(byte *)(iVar1 + 9)) {
    if (*(byte *)(iVar1 + 9) == 6) {
      *(undefined1 *)(iVar1 + 10) = 0x14;
    }
    else {
      *(undefined1 *)(iVar1 + 10) = 0x2d;
    }
  }
  *(undefined1 *)(iVar1 + 9) = 0;
  return;
}

