/* sub_0800F36C  (original: 0x0800F36C-0x0800F39C in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


undefined4 sub_0800F36C(short *param_1)

{
  undefined4 local_8;
  
  local_8 = CONCAT22((short)(param_1[1] + param_1[3]) >> 1,(short)(*param_1 + param_1[2]) >> 1);
  return local_8;
}

