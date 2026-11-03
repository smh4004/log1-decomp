/* sub_0800CAC8  (original: 0x0800CAC8-0x0800CB24 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r2();
extern int sub_080058D6();
extern int sub_0800236E();
extern int sub_0800507A();
extern int sub_080097F8();
extern int volatile DAT_03000600;
extern undefined volatile _0800F250;


void sub_0800CAC8(int param_1,int *param_2)

{
  int iVar1;
  unsigned int __frame[5];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_14 (*(undefined * *)((char *)__frame + 0x0))
#define local_10 (*(int *)((char *)__frame + 0x4))
  iVar1 = sub_080058D6((undefined2 *)(param_1 + 4));
  __call_via_r2(param_2,iVar1,(undefined *)(*(int *)(*param_2 + 8) + *param_2));
  sub_0800236E(&local_14,iVar1);
  sub_0800507A(DAT_03000600,(short *)&local_14,1,0);
  __call_via_r2(param_2,iVar1 + 0x20,(undefined *)(*(int *)(*param_2 + 0x1c) + *param_2));
  local_14 = &_0800F250;
  local_10 = iVar1;
  sub_080097F8((int *)&local_14);
  return;
}

