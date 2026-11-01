/* sub_08000F6C  (original: 0x08000F6C-0x08000F8C in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 50% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080098F8();
extern int sub_08009744();


undefined4 sub_08000F6C(int param_1)

{
  if (0x40 < *(byte *)(param_1 + 4)) {
    sub_080098F8();
    if (*(int *)(param_1 + 8) == 0) {
      return 1;
    }
    sub_08009744();
  }
  return 0;
}

