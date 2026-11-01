/* sub_08002E30  (original: 0x08002E30-0x08002E42 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern undefined4 volatile DAT_030007dc;
extern undefined4 volatile DAT_030007b4;


void sub_08002E30(void)

{
  DAT_030007dc = 1;
  DAT_030007b4 = sub_0800ACFE(0x12);
  return;
}

