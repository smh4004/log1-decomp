/* sub_0800CB24  (original: 0x0800CB24-0x0800CBA0 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r2();
extern int sub_0800C4C0();
extern int __call_via_r3();
extern int sub_0800507A();
extern int sub_080097F8();
extern int volatile DAT_03000600;
extern undefined volatile _0800F214;


void sub_0800CB24(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_20 (*(undefined4 *)((char *)__frame + 0x0))
#define local_1c (*(undefined4 *)((char *)__frame + 0x4))
#define local_18 (*(undefined4 *)((char *)__frame + 0x8))
#define local_14 (*(undefined4 *)((char *)__frame + 0xc))
  iVar1 = __call_via_r3();
  if (iVar1 != 0) {
    uVar2 = __call_via_r2(param_2,iVar1,(undefined *)(*(int *)(*param_2 + 0x18) + *param_2));
    sub_0800C4C0(iVar1,uVar2,(uint *)(param_1 + 8));
    uVar3 = *(uint *)(param_1 + 8);
    iVar1 = **(int **)(iVar1 + 0x1c);
    (*(undefined2 *)((char *)&local_18 + 0)) = (short)uVar3;
    (*(undefined2 *)((char *)&local_1c + 0)) = (short)iVar1;
    (*(undefined2 *)((char *)&local_1c + 2)) = (short)((uint)iVar1 >> 0x10);
    (*(undefined2 *)((char *)&local_18 + 2)) = (short)(uVar3 >> 0x10);
    local_20 = CONCAT22((*(undefined2 *)((char *)&local_18 + 2)) + (*(undefined2 *)((char *)&local_1c + 2)),(short)local_18 + (short)local_1c);
    local_14 = local_20;
    local_1c = (undefined *)iVar1;
    local_18 = uVar3;
    sub_0800507A(DAT_03000600,(short *)&local_18,1,0);
    local_1c = &_0800F214;
    sub_080097F8(&local_1c);
  }
  return;
}

