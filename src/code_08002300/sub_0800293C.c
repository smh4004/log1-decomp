/* sub_0800293C  (original: 0x0800293C-0x0800295E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08005478();


void sub_0800293C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x40) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    if (bVar1 == 0x3f) {
      sub_08005478(2,*(undefined1 *)(param_1 + 0x15),bVar1 >> 4,param_4,param_4);
    }
  }
  return;
}

