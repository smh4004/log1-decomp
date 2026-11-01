/* sub_080035CC  (original: 0x080035CC-0x080035E4 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int volatile DAT_030007e8;
extern ushort volatile DAT_03003d12;
extern uint volatile DAT_030007f0;


uint sub_080035CC(void)

{
  if (DAT_030007e8 == 0) {
    return 0;
  }
  return ((uint)DAT_03003d12 << 0x16) >> 0x1f ^ DAT_030007f0;
}

