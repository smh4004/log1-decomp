/* sub_08002CB8  (original: 0x08002CB8-0x08002CDE in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_08002CB8(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x30) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  *(char *)(param_1 + 0x12) = (char)((int)((uint)bVar1 << 0x1b) >> 0x1f) + '\x04';
  *(byte *)(param_1 + 0x10) = (bVar1 + 1 & 0x3f) + 0x40;
  return;
}

