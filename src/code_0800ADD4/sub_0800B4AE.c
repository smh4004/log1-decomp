/* sub_0800B4AE  (original: 0x0800B4AE-0x0800B4C4 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 72% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800B4AE(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 1;
  if (4 < bVar1) {
    *(undefined1 *)(param_1 + 0x10) = 0;
    return;
  }
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  return;
}

