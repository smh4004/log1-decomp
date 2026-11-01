/* sub_0800DCB8  (original: 0x0800DCB8-0x0800DCD4 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080060E6();
extern int volatile DAT_030005fc;


void sub_0800DCB8(int param_1)

{
  if (*(char *)(param_1 + 4) == DAT_030005fc) {
    sub_080060E6(param_1 + 8);
  }
  return;
}

