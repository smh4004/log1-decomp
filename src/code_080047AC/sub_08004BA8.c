/* sub_08004BA8  (original: 0x08004BA8-0x08004BCA in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08000954();
extern int sub_08005AE4();
extern int volatile DAT_030005fc;


void sub_08004BA8(int param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 5) == DAT_030005fc) && (iVar1 = sub_08000954(param_1), iVar1 != 0)) {
    sub_08005AE4(param_1);
  }
  return;
}

