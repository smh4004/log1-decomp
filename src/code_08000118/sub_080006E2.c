/* sub_080006E2  (original: 0x080006E2-0x08000700 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


uint sub_080006E2(byte *param_1)

{
  return ((uint)*param_1 ^ (param_1[1] ^ 3) << 2 ^ (param_1[2] ^ 3) << 6 ^ 1) & 0xff;
}

