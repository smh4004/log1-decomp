/* sub_08002A52  (original: 0x08002A52-0x08002A7A in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int sub_08002466();


void sub_08002A52(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x10) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 2;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  sub_08002466(param_1,0);
  __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x34) + 8));
  return;
}

