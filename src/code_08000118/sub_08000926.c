/* sub_08000926  (original: 0x08000926-0x08000954 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 8/8 snapshots, 60% of instructions covered.
 */
#include "ghidra_types.h"


undefined4 sub_08000926(int param_1,int param_2)

{
  if (param_2 - 0xbU < 3) {
    if (-1 < (int)((uint)*(byte *)(param_1 + 0x31) + (uint)*(byte *)(param_1 + 0x32) +
                   (uint)*(byte *)(param_1 + 0x33) + -6)) {
      return 1;
    }
  }
  else if ((param_2 == 0x13) && (-1 < (int)(*(byte *)(param_1 + 0x39) - 3))) {
    return 1;
  }
  return 0;
}

