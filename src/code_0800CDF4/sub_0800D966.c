/* sub_0800D966  (original: 0x0800D966-0x0800D97E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined2 volatile DAT_03000608;
extern undefined2 volatile DAT_0300060a;
extern undefined2 volatile REG_BG1HOFS;
extern undefined2 volatile REG_BG1VOFS;
extern undefined2 volatile REG_BG2HOFS;
extern undefined2 volatile REG_BG2VOFS;
extern undefined2 volatile REG_BG3HOFS;
extern undefined2 volatile REG_BG3VOFS;


void sub_0800D966(void)

{
  REG_BG1HOFS = DAT_03000608;
  REG_BG1VOFS = DAT_0300060a;
  REG_BG2HOFS = DAT_03000608;
  REG_BG2VOFS = DAT_0300060a;
  REG_BG3HOFS = DAT_03000608;
  REG_BG3VOFS = DAT_0300060a;
  return;
}

