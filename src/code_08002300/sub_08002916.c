/* sub_08002916  (original: 0x08002916-0x08002930 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 76% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08002916(int param_1)

{
  if ((*(byte *)(param_1 + 0x10) & 0x7f) < 0x71) {
    *(undefined1 *)(param_1 + 0x12) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x12) = 1;
  }
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) + 1;
  return;
}

