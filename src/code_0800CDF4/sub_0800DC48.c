/* sub_0800DC48  (original: 0x0800DC48-0x0800DC82 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002466();
extern int __call_via_r3();


void sub_0800DC48(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = __call_via_r3(param_2,*(undefined1 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2)
  ;
  if ((iVar1 != 0) &&
     (*(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0x28) + (uint)*(byte *)(param_1 + 5) * 0x10) != 0))
  {
    if (*(int *)(*(int *)(iVar1 + 0x18) + (uint)*(byte *)(param_1 + 5) * 0x14) != 0) {
      sub_08002466();
    }
  }
  return;
}

