/* sub_0800CDF4  (original: 0x0800CDF4-0x0800CE80 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r2();
extern int sub_080058D6();
extern int __call_via_r3();
extern int sub_0800236E();
extern int sub_0800507A();
extern int sub_080097F8();
extern int volatile DAT_03000600;
extern undefined volatile _0800F250;


void sub_0800CDF4(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(undefined * *)((char *)__frame + 0x0))
#define local_14 (*(undefined4 *)((char *)__frame + 0x4))
  iVar1 = sub_080058D6((undefined2 *)(param_1 + 4));
  __call_via_r2(param_2,iVar1,(undefined *)(*(int *)(*param_2 + 8) + *param_2));
  iVar2 = __call_via_r3();
  local_14 = CONCAT22(*(short *)(iVar2 + 0x22) + *(short *)(param_1 + 0x16),
                      *(short *)(iVar2 + 0x20) + *(short *)(param_1 + 0x14));
  *(undefined4 *)(iVar1 + 0x20) = local_14;
  __call_via_r2(param_2,(undefined4 *)(iVar1 + 0x20),
                (undefined *)(*(int *)(*param_2 + 0x1c) + *param_2));
  sub_0800236E(&local_18,iVar1);
  sub_0800507A(DAT_03000600,(short *)&local_18,1,0);
  local_18 = &_0800F250;
  local_14 = iVar1;
  sub_080097F8((int *)&local_18);
  return;
}

