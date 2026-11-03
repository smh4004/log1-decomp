/* sub_0800AB00  (original: 0x0800AB00-0x0800AB12 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int WaitForVBlank();
extern ushort volatile DAT_04000102;


void sub_0800AB00(void)

{
  WaitForVBlank(0x400);
  DAT_04000102 = 0;
  return;
}

