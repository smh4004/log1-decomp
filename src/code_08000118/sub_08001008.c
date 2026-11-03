/* sub_08001008  (original: 0x08001008-0x0800102E in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 62% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009328();
extern int sub_08001FA8();
extern int sub_080007D2();
extern int volatile DAT_02029da8;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0800fee0;


undefined4 sub_08001008(void)

{
  sub_08009328(&DAT_02029d94,0);
  if (DAT_02029da8 == 0) {
    sub_080007D2(0x3000028);
    sub_08001FA8(0,(undefined4 *)&DAT_0800fee0);
  }
  return 0;
}

