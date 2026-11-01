/* sub_080096B4  (original: 0x080096B4-0x080096CC in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int * volatile DAT_03003b64;
extern int volatile DAT_03003b6c;


void sub_080096B4(void)

{
  __call_via_r1(DAT_03003b64,*(int *)(*DAT_03003b64 + 0x10) + *DAT_03003b64);
  DAT_03003b6c = DAT_03003b6c + 1;
  return;
}

