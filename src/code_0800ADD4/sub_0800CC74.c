/* sub_0800CC74  (original: 0x0800CC74-0x0800CC98 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_08000E7A();
extern ushort volatile DAT_03003d14;
extern byte volatile DAT_03003d10;
extern undefined4 volatile DAT_030000e8;


void sub_0800CC74(int param_1)

{
  sub_08000E7A(&DAT_030000e8,(uint)*(byte *)(param_1 + 4));
  DAT_03003d14 = 0;
  DAT_03003d10 = 0;
  return;
}

