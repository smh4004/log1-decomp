/* sub_0800B644  (original: 0x0800B644-0x0800B660 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800283C();
extern int volatile DAT_030005fc;


void sub_0800B644(int param_1)

{
  if (*(char *)(param_1 + 4) == DAT_030005fc) {
    sub_0800283C(2,(uint)*(byte *)(param_1 + 5));
  }
  return;
}

