/* sub_0800CBB4  (original: 0x0800CBB4-0x0800CBDA in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int __call_via_r2();
extern int volatile DAT_03004630;
extern int volatile DAT_0300462c;
extern int * volatile DAT_03004628;


void sub_0800CBB4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __call_via_r1(param_1,*(undefined4 *)(DAT_03004630 + 4),param_3,param_4,param_4);
  if (0x40 < DAT_0300462c) {
    __call_via_r2(DAT_03004628,param_1,*(int *)(*DAT_03004628 + 0xc) + *DAT_03004628);
  }
  return;
}

