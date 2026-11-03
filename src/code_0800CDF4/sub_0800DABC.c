/* sub_0800DABC  (original: 0x0800DABC-0x0800DADC in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 86% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000954();
extern int volatile DAT_030005fc;


undefined4 sub_0800DABC(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}

