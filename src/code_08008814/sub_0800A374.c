/* sub_0800A374  (original: 0x0800A374-0x0800A38C in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E640();
extern undefined1 volatile DAT_03003d01;
extern ushort volatile DAT_03003d2e;
extern undefined2 volatile DAT_03003d04;


void sub_0800A374(undefined4 param_1)

{
  DAT_03003d01 = (undefined1)param_1;
  DAT_03003d04 = sub_0800E640(param_1,(uint)DAT_03003d2e * 2 + (uint)(DAT_03003d2e >> 1));
  return;
}

