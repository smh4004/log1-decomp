/* sub_0800A38C  (original: 0x0800A38C-0x0800A3A6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_0800A38C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 10);
  if (((*(byte *)(param_1 + 10) & 3) != 0) && (((uVar1 & 3) != 1 || ((int)(uVar1 << 0x1d) < 0)))) {
    __call_via_r1(param_1,*(undefined4 *)(param_1 + 0x14),uVar1,param_4,param_4);
  }
  return;
}

