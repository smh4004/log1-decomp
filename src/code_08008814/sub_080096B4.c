/* sub_080096B4  (original: 0x080096B4-0x080096CC in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int * volatile DAT_03003b64;
extern int volatile DAT_03003b6c;


undefined4 sub_080096B4(void)
{
  undefined4 __r0 = 0;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  __r0 = (undefined4)__call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 0x10) + *DAT_03003b64));
  DAT_03003b6c = DAT_03003b6c + 1;
  return __r0;
  return __r0;
}
