/* sub_080062C4  (original: 0x080062C4-0x080062FC in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 8/8 snapshots, 71% of instructions covered.
 */
#include "ghidra_types.h"


void sub_080062C4(int *param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x274) = param_3;
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

