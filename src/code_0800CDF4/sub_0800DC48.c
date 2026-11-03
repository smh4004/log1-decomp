/* sub_0800DC48  (original: 0x0800DC48-0x0800DC82 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r3();
extern int sub_08002466();


void sub_0800DC48(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __call_via_r3();
  if (((iVar1 != 0) &&
      (uVar2 = (uint)*(byte *)(param_1 + 5),
      *(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0x28) + uVar2 * 0x10) != 0)) &&
     (*(int *)(*(int *)(iVar1 + 0x18) + uVar2 * 0x14) != 0)) {
    sub_08002466(iVar1,uVar2);
  }
  return;
}

