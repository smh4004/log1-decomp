/* sub_0800ED74  (original: 0x0800ED74-0x0800ED90 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined * volatile DAT_030005d8;
extern undefined * volatile DAT_030005e0;
extern undefined volatile _0800F0B4;
extern undefined volatile _0800F064;


void sub_0800ED74(void)

{
  DAT_030005d8 = &_0800F064;
  DAT_030005e0 = &_0800F0B4;
  return;
}

