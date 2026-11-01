/* sub_08002C84  (original: 0x08002C84-0x08002CAA in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 42% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08002C84(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x18) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 3;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  *(char *)(param_1 + 0x12) = (char)((int)((uint)bVar1 << 0x1c) >> 0x1f) + '\x02';
  *(byte *)(param_1 + 0x10) = (bVar1 + 1 & 0x1f) + 0x20;
  return;
}

