/* sub_0800F570  (original: 0x0800F570-0x0800F588 in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


int sub_0800F570(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  param_1 = param_1 - param_3;
  iVar2 = -param_1;
  if (-1 < param_1) {
    iVar2 = param_1;
  }
  param_2 = param_2 - param_4;
  iVar1 = -param_2;
  if (-1 < param_2) {
    iVar1 = param_2;
  }
  return iVar2 + iVar1;
}

