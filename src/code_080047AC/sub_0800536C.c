/* sub_0800536C  (original: 0x0800536C-0x08005380 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_080051D0();
extern undefined volatile DAT_03000076;


void sub_0800536C(int param_1,undefined1 param_2)

{
  (&DAT_03000076)[param_1] = param_2;
  sub_080051D0(param_1,&DAT_03000076 + param_1);
  return;
}

