/* sub_0800236E  (original: 0x0800236E-0x08002396 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800236E(undefined4 *param_1,int param_2)

{
  undefined4 local_8;
  
  local_8 = CONCAT22(*(short *)(param_2 + 0x22) + (*(short **)(param_2 + 0x1c))[1],
                     *(short *)(param_2 + 0x20) + **(short **)(param_2 + 0x1c));
  *param_1 = *(undefined4 *)(param_2 + 0x20);
  param_1[1] = local_8;
  return;
}

