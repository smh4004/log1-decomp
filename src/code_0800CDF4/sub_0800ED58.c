/* sub_0800ED58  (original: 0x0800ED58-0x0800ED74 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_long.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern undefined * volatile DAT_030005c4;
extern undefined * volatile DAT_030005cc;
extern undefined volatile _0800F1B0;
extern undefined volatile _0800F11C;


void sub_0800ED58(void)

{
  DAT_030005c4 = &_0800F11C;
  DAT_030005cc = &_0800F1B0;
  return;
}

