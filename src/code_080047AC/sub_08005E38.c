/* sub_08005E38  (original: 0x08005E38-0x08005E4C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08003B28();


undefined4 sub_08005E38(int param_1)
{
  undefined4 __r0 = (undefined4)param_1;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  __r0 = (undefined4)sub_08003B28(param_1);
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(*(int *)(param_1 + 0x3c) + 8);
  *(undefined4 *)(param_1 + 0x24) = 0;
  return __r0;
  return __r0;
}
