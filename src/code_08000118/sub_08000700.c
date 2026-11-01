/* sub_08000700  (original: 0x08000700-0x08000732 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_08000700(byte *param_1)

{
  if ((((uint)*param_1 ^ (param_1[1] ^ 3) << 2 ^ (param_1[2] ^ 3) << 6 ^ 1) & 0xff) !=
      (uint)param_1[3]) {
    *param_1 = 0;
    param_1[1] = 4;
    param_1[2] = 8;
    param_1[3] = 0;
  }
  return;
}

