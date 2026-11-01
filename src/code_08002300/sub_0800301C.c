/* sub_0800301C  (original: 0x0800301C-0x08003032 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int volatile DAT_030007b4;


void sub_0800301C(void)

{
  if (DAT_030007b4 != 0) {
    *(byte *)(DAT_030007b4 + 0xc) = *(byte *)(DAT_030007b4 + 0xc) & 0xfe;
    DAT_030007b4 = 0;
  }
  return;
}

