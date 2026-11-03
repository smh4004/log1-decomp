/* sub_0800B66E  (original: 0x0800B66E-0x0800B692 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 81% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800B436();
extern int sub_08002466();
extern ushort volatile DAT_03003d12;


void sub_0800B66E(int param_1)

{
  if ((int)((uint)DAT_03003d12 << 0x1e) < 0) {
    sub_0800B436(param_1,*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x58) + 0xf >> 4);
  }
  else {
    sub_08002466(param_1,1);
  }
  return;
}

