/* sub_08006074  (original: 0x08006074-0x08006096 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 80% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080060E6();
extern int sub_08000954();
extern int volatile DAT_030005fc;


void sub_08006074(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    sub_080060E6(param_1 + 8);
  }
  return;
}

