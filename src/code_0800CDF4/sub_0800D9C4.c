/* sub_0800D9C4  (original: 0x0800D9C4-0x0800DA6C in asm/code_0800CDF4.s)
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


void sub_0800D9C4(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  unsigned int __frame[9];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_24 (*(undefined4 *)((char *)__frame + 0x0))
#define local_20 (*(undefined4 *)((char *)__frame + 0x4))
#define local_1c (*(undefined4 *)((char *)__frame + 0x8))
#define local_18 (*(undefined4 *)((char *)__frame + 0xc))
#define local_14 (*(uint *)((char *)__frame + 0x10))
  iVar2 = __call_via_r3();
  iVar3 = __call_via_r3();
  if ((iVar2 != 0) && (iVar3 != 0)) {
    local_18 = CONCAT22(*(short *)(iVar3 + 0x22) + *(short *)(param_1 + 10),
                        *(short *)(iVar3 + 0x20) + *(short *)(param_1 + 8));
    local_14 = local_18;
    uVar4 = __call_via_r2(param_2,iVar2,(undefined *)(*(int *)(*param_2 + 0x18) + *param_2));
    sub_0800C4C0(iVar2,uVar4,&local_14);
    local_1c = local_14;
    uVar1 = local_1c;
    iVar2 = **(int **)(iVar2 + 0x1c);
    (*(undefined2 *)((char *)&local_1c + 0)) = (short)local_14;
    (*(undefined2 *)((char *)&local_20 + 0)) = (short)iVar2;
    (*(undefined2 *)((char *)&local_20 + 2)) = (short)((uint)iVar2 >> 0x10);
    (*(undefined2 *)((char *)&local_1c + 2)) = (short)(local_14 >> 0x10);
    local_24 = CONCAT22((*(undefined2 *)((char *)&local_1c + 2)) + (*(undefined2 *)((char *)&local_20 + 2)),(short)local_1c + (short)local_20);
    local_18 = local_24;
    local_20 = (undefined *)iVar2;
    local_1c = uVar1;
    sub_0800507A(DAT_03000600,(short *)&local_1c,1,0);
    local_20 = &_0800F214;
    sub_080097F8(&local_20);
  }
  return;
}

