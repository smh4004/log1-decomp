/* sub_0800BF30  (original: 0x0800BF30-0x0800BF4E in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 69% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800B436();
extern int sub_08002466();


void sub_0800BF30(int param_1)

{
  if (*(int *)(param_1 + 0x24) < *(int *)(param_1 + 0x2c)) {
    sub_0800B436(param_1,*(int *)(param_1 + 0x2c) + 7 >> 3);
  }
  else {
    *(undefined1 *)(param_1 + 0x16) = 1;
    sub_08002466(param_1,1);
  }
  return;
}

