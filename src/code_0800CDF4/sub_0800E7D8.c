/* sub_0800E7D8  (original: 0x0800E7D8-0x0800E802 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E95C();
extern int sub_0800E98C();


bool sub_0800E7D8(int *param_1,int param_2)

{
  int iVar1;
  unsigned int __frame[3];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_c (*(int * *)((char *)__frame + 0x0))
  iVar1 = sub_0800E98C(param_2,(int)&local_c);
  if (iVar1 != 0) {
    sub_0800E95C(param_1,local_c,iVar1);
  }
  return iVar1 != 0;
}

