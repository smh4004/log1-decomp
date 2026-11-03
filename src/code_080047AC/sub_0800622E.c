/* sub_0800622E  (original: 0x0800622E-0x08006244 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_0800C42E();
extern undefined volatile gUnknown_0815A778;


void sub_0800622E(int param_1)

{
  sub_0800C42E((int *)(&gUnknown_0815A778 + (uint)*(byte *)(param_1 + 4) * 8));
  return;
}

