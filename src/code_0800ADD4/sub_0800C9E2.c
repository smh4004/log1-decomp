/* sub_0800C9E2  (original: 0x0800C9E2-0x0800CA16 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080024B8();
extern int __call_via_r1();
extern undefined4 volatile DAT_030007e0;


void sub_0800C9E2(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 4;
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  if (0x4f < (byte)(bVar1 + 1)) {
    sub_080024B8(param_1,0x85c1f64,0,0);
    __call_via_r1(param_1,*(undefined **)(*(int *)(param_1 + 0x34) + 8));
    DAT_030007e0 = 0x48;
  }
  return;
}

