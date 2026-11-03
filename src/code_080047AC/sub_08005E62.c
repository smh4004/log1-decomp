/* sub_08005E62  (original: 0x08005E62-0x08005E80 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 33% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08005E62(int param_1)

{
  byte bVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    *(undefined1 *)(param_1 + 0x12) = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x10);
    if (bVar1 < 0x10) {
      *(char *)(param_1 + 0x12) = '\x01' - (char)((int)((uint)bVar1 << 0x1c) >> 0x1f);
      *(byte *)(param_1 + 0x10) = bVar1 + 1;
      return;
    }
  }
  return;
}

