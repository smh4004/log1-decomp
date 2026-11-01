/* sub_08004B60  (original: 0x08004B60-0x08004B80 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08005A94();
extern int sub_08000954();
extern int volatile DAT_030005fc;


void sub_08004B60(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954();
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    sub_08005A94(param_1);
  }
  return;
}

