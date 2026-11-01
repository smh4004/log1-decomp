/* sub_0800DC0C  (original: 0x0800DC0C-0x0800DC48 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080024B8();
extern int __call_via_r3();
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;


void sub_0800DC0C(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __call_via_r3(param_2,*(undefined1 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2,
                        param_4);
  sub_080024B8(iVar1,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 5)]],0,0);
  *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 5);
  return;
}

