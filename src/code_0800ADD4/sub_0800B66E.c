/* sub_0800B66E  (original: 0x0800B66E-0x0800B692 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002466();
extern int sub_0800B436();
extern ushort volatile DAT_03003d12;


void sub_0800B66E(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((int)((uint)DAT_03003d12 << 0x1e) < 0) {
    sub_0800B436(param_1,*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x58) + 0xf >> 4);
  }
  else {
    sub_08002466(param_1,1,0,param_4,param_4);
  }
  return;
}

