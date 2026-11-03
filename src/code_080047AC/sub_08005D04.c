/* sub_08005D04  (original: 0x08005D04-0x08005DA6 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 55% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002300();
extern int sub_0800994C();
extern int sub_0800ACFE();
extern int sub_08005526();
extern int sub_08003398();
extern int __call_via_r2();
extern int sub_0800507A();
extern int volatile DAT_03000600;
extern undefined volatile DAT_085c2258;


undefined4 sub_08005D04(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  unsigned int __frame[9];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define sStack_24 (*(short *)((char *)__frame + 0x0))
#define sStack_22 (*(short *)((char *)__frame + 0x2))
#define local_20 (*(short *)((char *)__frame + 0x4))
#define local_1e (*(short *)((char *)__frame + 0x6))
#define local_1c (*(undefined4 *)((char *)__frame + 0x8))
#define local_18 (*(short *)((char *)__frame + 0xc))
#define local_16 (*(short *)((char *)__frame + 0xe))
#define local_14 (*(undefined2 *)((char *)__frame + 0x10))
#define local_12 (*(undefined2 *)((char *)__frame + 0x12))
  if (param_2 == 0) {
    sub_08002300((undefined4 *)&local_20,param_1);
    local_18 = local_20;
    local_16 = local_1e;
    local_14 = (short)local_1c;
    local_12 = (*(undefined2 *)((char *)&local_1c + 2));
    sub_0800994C(&sStack_24,&local_18,2);
    uVar1 = sub_08003398();
    (*(undefined2 *)((char *)&local_1c + 0)) = (short)uVar1;
    if ((((sStack_24 <= (short)local_1c) && ((short)local_1c < local_20)) &&
        ((*(undefined2 *)((char *)&local_1c + 2)) = (short)((uint)uVar1 >> 0x10), sStack_22 <= (*(undefined2 *)((char *)&local_1c + 2)))) &&
       ((*(undefined2 *)((char *)&local_1c + 2)) < local_1e)) {
      iVar3 = *(int *)(param_1 + 0x3c);
      local_1c = uVar1;
      sub_0800ACFE(7);
      uVar2 = (uint)*(byte *)(iVar3 + 6);
      __call_via_r2(param_1,uVar2,*(undefined **)(&DAT_085c2258 + uVar2 * 0x18));
      sub_08005526((uint)*(byte *)(iVar3 + 4));
      sub_0800507A(DAT_03000600,&local_18,1,0);
      return 1;
    }
  }
  return 0;
}

