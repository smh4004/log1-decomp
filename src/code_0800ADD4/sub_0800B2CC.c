/* sub_0800B2CC  (original: 0x0800B2CC-0x0800B2DE in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


undefined4 sub_0800B2CC(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + 1;
  *(int *)(param_1 + 4) = iVar1;
  if (0x40 < iVar1) {
    return 1;
  }
  return 0;
}

