/* sub_0800DBCC  (original: 0x0800DBCC-0x0800DBDC in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_0800DBCC(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x40) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
  }
  return;
}

