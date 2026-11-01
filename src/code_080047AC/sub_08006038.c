/* sub_08006038  (original: 0x08006038-0x0800604C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800640C();
extern int volatile DAT_030005fc;


void sub_08006038(int param_1)

{
  if (*(char *)(param_1 + 5) == DAT_030005fc) {
    sub_0800640C();
  }
  return;
}

