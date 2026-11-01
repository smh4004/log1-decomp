/* sub_08006294  (original: 0x08006294-0x080062C4 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_08006294(int *param_1,int param_2)

{
  if (param_1[1] == 0) {
    param_1[1] = param_2;
    param_1[2] = param_2;
    *(undefined4 *)(param_2 + 0xa4) = 0;
    *(undefined4 *)(param_2 + 0xa0) = 0;
  }
  else {
    *(int *)(param_2 + 0xa4) = param_1[2];
    *(undefined4 *)(param_2 + 0xa0) = 0;
    *(int *)(param_1[2] + 0xa0) = param_2;
    param_1[2] = param_2;
  }
  *param_1 = *param_1 + 1;
  return;
}

