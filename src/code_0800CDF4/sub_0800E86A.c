/* sub_0800E86A  (original: 0x0800E86A-0x0800E880 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E7C4();
extern int sub_0800E8F2();


void sub_0800E86A(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = sub_0800E7C4();
  sub_0800E8F2(*(undefined4 *)(iVar1 + 8),param_1);
  return;
}

