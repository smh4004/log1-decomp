/* sub_080029A6  (original: 0x080029A6-0x080029F8 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08002466();


void sub_080029A6(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10) & 0x7f;
  if (bVar1 == 0x70) {
    if (((*(int *)(param_1 + 0x24) == 4) &&
        (*(int *)(*(int *)(*(int *)(param_1 + 0x1c) + 0x28) + 0xf0) != 0)) &&
       (*(int *)(*(int *)(param_1 + 0x18) + 300) != 0)) {
      sub_08002466(param_1,0xf);
    }
    else {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    }
  }
  else if (bVar1 < 0x71) {
    *(undefined1 *)(param_1 + 0x12) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x12) = 1;
  }
  *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
  return;
}

