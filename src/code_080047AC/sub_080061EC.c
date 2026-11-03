/* sub_080061EC  (original: 0x080061EC-0x08006214 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800507A();
extern int volatile DAT_030005fc;
extern int volatile DAT_03000600;


void sub_080061EC(int param_1)

{
  if (*(char *)(param_1 + 0xc) == DAT_030005fc) {
    sub_0800507A(DAT_03000600,(short *)(param_1 + 4),1,0);
  }
  return;
}

