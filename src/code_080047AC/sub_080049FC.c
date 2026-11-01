/* sub_080049FC  (original: 0x080049FC-0x08004A1C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 86% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000954();
extern int volatile DAT_030005fc;


undefined4 sub_080049FC(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954();
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}

