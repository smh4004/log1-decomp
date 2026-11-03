/* sub_08006278  (original: 0x08006278-0x0800628C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800B18E();
extern int volatile DAT_030005fc;


void sub_08006278(int param_1)

{
  if (*(char *)(param_1 + 5) == DAT_030005fc) {
    sub_0800B18E(param_1);
  }
  return;
}

