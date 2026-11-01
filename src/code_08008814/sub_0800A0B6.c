/* sub_0800A0B6  (original: 0x0800A0B6-0x0800A0E0 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A0B6(int param_1)

{
  sub_08009A20();
  if (*(char *)(param_1 + 0x1e) != '\0') {
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0x1e);
  }
  *(undefined4 *)(param_1 + 0x14) = 0x800a093;
  *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0xe) & 0xf;
  *(byte *)(param_1 + 10) = (*(byte *)(param_1 + 10) & 0xfc) + 2;
  return;
}

