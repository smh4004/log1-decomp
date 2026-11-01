/* sub_0800ECB4  (original: 0x0800ECB4-0x0800ECD0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined * volatile DAT_030000e4;
extern undefined * volatile DAT_030000e8;
extern undefined volatile _0800F1C8;
extern undefined volatile _0800F0D0;


void sub_0800ECB4(void)

{
  DAT_030000e4 = &_0800F1C8;
  DAT_030000e8 = &_0800F0D0;
  return;
}

