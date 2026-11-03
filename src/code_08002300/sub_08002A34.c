/* sub_08002A34  (original: 0x08002A34-0x08002A52 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002E80();
extern int sub_08002466();
extern ushort volatile DAT_03003d12;


void sub_08002A34(int param_1)

{
  if (((uint)DAT_03003d12 << 0x18) >> 0x1c != 0) {
    sub_08002466(param_1,1);
  }
  sub_08002E80(param_1);
  return;
}

