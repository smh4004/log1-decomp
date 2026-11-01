/* sub_0800CBA0  (original: 0x0800CBA0-0x0800CBB4 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800279E();
extern int sub_080026F8();


int sub_0800CBA0(int param_1)

{
  int iVar1;
  
  sub_080026F8();
  iVar1 = sub_0800279E(*(undefined4 *)(param_1 + 4));
  return 1 - iVar1;
}

