/* sub_0800A06C  (original: 0x0800A06C-0x0800A090 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A06C(int param_1)

{
  int *piVar1;
  
  sub_08009A20();
  if ((*(byte *)(param_1 + 0x18) & 0x11) != 0) {
    piVar1 = *(int **)(param_1 + 0x20);
    *piVar1 = (uint)*(byte *)(param_1 + 0x1e) << 0x16;
    *(byte *)(piVar1 + 3) = *(byte *)(piVar1 + 3) & 0xfb;
  }
  return;
}

