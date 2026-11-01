/* sub_0800BF30  (original: 0x0800BF30-0x0800BF4E in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002466();
extern int sub_0800B436();


void sub_0800BF30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(param_1 + 0x24) < *(int *)(param_1 + 0x2c)) {
    sub_0800B436(param_1,*(int *)(param_1 + 0x2c) + 7 >> 3,*(int *)(param_1 + 0x24),param_4,param_4)
    ;
  }
  else {
    *(undefined1 *)(param_1 + 0x16) = 1;
    sub_08002466();
  }
  return;
}

