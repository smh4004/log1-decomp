/* sub_080049D4  (original: 0x080049D4-0x080049F4 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005DA6();
extern int sub_08000954();
extern int volatile DAT_030005fc;


void sub_080049D4(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    sub_08005DA6(param_1);
  }
  return;
}

