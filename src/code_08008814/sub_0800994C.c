/* sub_0800994C  (original: 0x0800994C-0x0800996A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800994C(short *param_1,short *param_2,short param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = param_2[1];
  sVar2 = param_2[2];
  sVar3 = param_2[3];
  *param_1 = *param_2 - param_3;
  param_1[1] = sVar1 - param_3;
  param_1[2] = sVar2 + param_3;
  param_1[3] = sVar3 + param_3;
  return;
}

