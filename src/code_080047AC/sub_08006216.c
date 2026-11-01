/* sub_08006216  (original: 0x08006216-0x0800622C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern byte volatile DAT_0300004d;


void sub_08006216(int param_1)

{
  DAT_0300004d = DAT_0300004d | (byte)(1 << *(sbyte *)(param_1 + 4));
  return;
}

