/* sub_08002C4C  (original: 0x08002C4C-0x08002C76 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int sub_08002466();


void sub_08002C4C(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 4;
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  if (0x2f < (byte)(bVar1 + 1)) {
    sub_08002466(param_1,0);
    __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x34) + 8));
  }
  return;
}

