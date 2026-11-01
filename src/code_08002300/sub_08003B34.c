/* sub_08003B34  (original: 0x08003B34-0x08003B5A in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_08003B34(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x18) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 3;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  *(char *)(param_1 + 0x12) = (char)((int)((uint)bVar1 << 0x1c) >> 0x1f) + '\x02';
  *(byte *)(param_1 + 0x10) = (bVar1 + 1 & 0xf) + 0x10;
  return;
}

