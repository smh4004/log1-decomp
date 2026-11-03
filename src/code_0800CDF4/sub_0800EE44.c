/* sub_0800EE44  (original: 0x0800EE44-0x0800EEC0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: stays assembly: its range in the disassembly also holds the static-constructor table (0x0800EE54-0x0800EEBB) that sub_0800E4B0 walks at startup; replacing it would erase the table.
 */
#include "ghidra_types.h"
extern undefined volatile _0800F14C;
extern undefined * volatile DAT_0300463c;


void sub_0800EE44(void)

{
  DAT_0300463c = &_0800F14C;
  return;
}

