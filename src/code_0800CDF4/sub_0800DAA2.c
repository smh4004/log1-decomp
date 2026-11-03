/* sub_0800DAA2  (original: 0x0800DAA2-0x0800DABC in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800A5F6();
extern undefined volatile gUnknown_08591F3C;


void sub_0800DAA2(int param_1)

{
  sub_0800A5F6((int)(&gUnknown_08591F3C + (uint)*(byte *)(param_1 + 4) * 0xc));
  return;
}

