/* sub_080006B0  (original: 0x080006B0-0x080006D2 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


uint sub_080006B0(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  uVar3 = 0;
  do {
    uVar2 = (uVar2 >> 0x1d | uVar2 << 3) + (uint)*param_1 + 1;
    uVar1 = uVar1 ^ uVar2;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xa8);
  return uVar1;
}

