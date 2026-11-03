/* sub_08002300  (original: 0x08002300-0x08002328 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08002300(undefined4 *param_1,int param_2)

{
  undefined4 local_8;
  
  local_8 = CONCAT22(*(short *)(param_2 + 0x22) + *(short *)(param_2 + 6),
                     *(short *)(param_2 + 0x20) + *(short *)(param_2 + 4));
  *param_1 = *(undefined4 *)(param_2 + 0x20);
  param_1[1] = local_8;
  return;
}

