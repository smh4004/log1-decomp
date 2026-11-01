/* sub_080035B6  (original: 0x080035B6-0x080035CC in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern ushort volatile DAT_03003d14;
extern int volatile DAT_030007f0;


void sub_080035B6(void)

{
  if ((int)((uint)DAT_03003d14 << 0x1d) < 0) {
    DAT_030007f0 = 1 - DAT_030007f0;
  }
  return;
}

