/* sub_08002C04  (original: 0x08002C04-0x08002C18 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();


void sub_08002C04(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  sub_0800ACFE(2);
  return;
}

