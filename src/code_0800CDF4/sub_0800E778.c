/* sub_0800E778  (original: 0x0800E778-0x0800E7A2 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E7C4();
extern int __call_via_r0();
extern int sub_0800E86A();


int sub_0800E778(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if (param_1 != 0) {
    iVar1 = param_1;
  }
  iVar1 = sub_0800E86A(iVar1);
  if (iVar1 == 0) {
    iVar2 = sub_0800E7C4();
    if (*(int *)(iVar2 + 0x34) != 0) {
      __call_via_r0();
    }
  }
  return iVar1;
}

