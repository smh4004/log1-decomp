/* sub_0800F404  (original: 0x0800F404-0x0800F41E in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


undefined4 sub_0800F404(short *param_1,uint param_2)

{
  return CONCAT22((short)((int)param_1[1] << (param_2 & 0xff)),
                  (short)((int)*param_1 << (param_2 & 0xff)));
}

