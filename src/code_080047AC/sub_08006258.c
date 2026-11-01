/* sub_08006258  (original: 0x08006258-0x08006278 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08000954();
extern int volatile DAT_030005fc;


undefined4 sub_08006258(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954();
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}

