/* sub_0800A120  (original: 0x0800A120-0x0800A15E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009A20();
extern int sub_08009DB0();


void sub_0800A120(int param_1)

{
  byte bVar1;
  
  sub_08009A20();
  if ((*(byte *)(param_1 + 0x18) & 0x11) != 0) {
    *(undefined1 *)(param_1 + 0x11) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0x1e);
  if ((bVar1 & 0xf) != 0) {
    *(byte *)(param_1 + 0x10) = bVar1 & 0xf;
  }
  if (((uint)bVar1 << 0x18) >> 0x1c != 0) {
    *(byte *)(param_1 + 0xf) = bVar1 >> 4;
  }
  *(undefined4 *)(param_1 + 0x14) = 0x8009db1;
  *(byte *)(param_1 + 10) = *(byte *)(param_1 + 10) | 1;
  sub_08009DB0(param_1);
  return;
}

