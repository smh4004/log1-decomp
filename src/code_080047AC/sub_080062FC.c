/* sub_080062FC  (original: 0x080062FC-0x08006330 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_080062FC(int *param_1,int param_2)

{
  if (*(int *)(param_2 + 0xa0) == 0) {
    param_1[2] = *(int *)(param_2 + 0xa4);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0xa0) + 0xa4) = *(undefined4 *)(param_2 + 0xa4);
  }
  if (*(int *)(param_2 + 0xa4) == 0) {
    param_1[1] = *(int *)(param_2 + 0xa0);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0xa4) + 0xa0) = *(undefined4 *)(param_2 + 0xa0);
  }
  *(undefined4 *)(param_2 + 0xa4) = 0;
  *(undefined4 *)(param_2 + 0xa0) = 0;
  *param_1 = *param_1 + -1;
  return;
}

