/* sub_0800DBE8  (original: 0x0800DBE8-0x0800DBF8 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_0800DBE8(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x50) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
  }
  return;
}

