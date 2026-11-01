/* sub_0800CC74  (original: 0x0800CC74-0x0800CC98 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08000E7A();
extern undefined2 volatile DAT_03003d14;
extern undefined1 volatile DAT_03003d10;
extern undefined4 volatile DAT_030000e8;


void sub_0800CC74(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_08000E7A(&DAT_030000e8,*(undefined1 *)(param_1 + 4),param_3,param_4,param_4);
  DAT_03003d14 = 0;
  DAT_03003d10 = 0;
  return;
}

