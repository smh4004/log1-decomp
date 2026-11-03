/* sub_0800296C  (original: 0x0800296C-0x08002996 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002466();
extern int __call_via_r1();


void sub_0800296C(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 3;
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  if (0x1f < (byte)(bVar1 + 1)) {
    sub_08002466(param_1,0);
    __call_via_r1(param_1,*(undefined **)(*(int *)(param_1 + 0x34) + 8));
  }
  return;
}

