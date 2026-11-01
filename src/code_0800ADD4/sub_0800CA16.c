/* sub_0800CA16  (original: 0x0800CA16-0x0800CA28 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_030043a0;


void sub_0800CA16(int param_1)

{
  if (*(char *)(param_1 + 0x10) == 'P') {
    DAT_030043a0 = 0;
    *(undefined1 *)(param_1 + 0x10) = 0x51;
  }
  return;
}

