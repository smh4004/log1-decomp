/* sub_0800A38C  (original: 0x0800A38C-0x0800A3A6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_0800A38C(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 10);
  if (((bVar1 & 3) != 0) && (((bVar1 & 3) != 1 || ((int)((uint)bVar1 << 0x1d) < 0)))) {
    __call_via_r1(param_1,*(undefined **)(param_1 + 0x14));
  }
  return;
}

