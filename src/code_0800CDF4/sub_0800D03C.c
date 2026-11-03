/* sub_0800D03C  (original: 0x0800D03C-0x0800D11C in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 43% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000926();
extern int __call_via_r2();
extern int sub_08002300();
extern int sub_08004E98();
extern int sub_08003398();
extern int sub_0800ACFE();
extern int sub_0800994C();
extern int sub_0800507A();
extern int volatile DAT_03000600;
extern undefined volatile DAT_085c2258;


undefined4 sub_0800D03C(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  unsigned int __frame[10];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_28 (*(short *)((char *)__frame + 0x0))
#define sStack_26 (*(short *)((char *)__frame + 0x2))
#define local_24 (*(short *)((char *)__frame + 0x4))
#define local_22 (*(short *)((char *)__frame + 0x6))
#define local_20 (*(undefined4 *)((char *)__frame + 0x8))
#define local_1c (*(short *)((char *)__frame + 0xc))
#define local_1a (*(short *)((char *)__frame + 0xe))
#define local_18 (*(undefined2 *)((char *)__frame + 0x10))
#define local_16 (*(undefined2 *)((char *)__frame + 0x12))
  if (param_2 == 0) {
    sub_08002300((undefined4 *)&local_24,param_1);
    local_1c = local_24;
    local_1a = local_22;
    local_18 = (short)local_20;
    local_16 = (*(undefined2 *)((char *)&local_20 + 2));
    sub_0800994C(&local_28,&local_1c,2);
    uVar1 = sub_08003398();
    (*(undefined2 *)((char *)&local_20 + 0)) = (short)uVar1;
    if ((((local_28 <= (short)local_20) && ((short)local_20 < local_24)) &&
        ((*(undefined2 *)((char *)&local_20 + 2)) = (short)((uint)uVar1 >> 0x10), sStack_26 <= (*(undefined2 *)((char *)&local_20 + 2)))) &&
       ((*(undefined2 *)((char *)&local_20 + 2)) < local_22)) {
      iVar4 = *(int *)(param_1 + 0x3c);
      local_20 = uVar1;
      iVar2 = sub_08000926(0x3000028,iVar4);
      if (iVar2 != 0) {
        sub_0800ACFE(5);
        pcVar3 = "You can\'t possibly carry more Senzu beans!";
        if (iVar4 != 0x13) {
          pcVar3 = "You can\'t possibly carry more herbs!";
        }
        sub_08004E98(0x3000864,(int)pcVar3);
        return 1;
      }
      sub_0800ACFE(7);
      __call_via_r2(param_1,iVar4,*(undefined **)(&DAT_085c2258 + iVar4 * 0x18));
      sub_0800507A(DAT_03000600,&local_1c,1,0);
      return 1;
    }
  }
  else if (param_2 == 6) {
    sub_08002300((undefined4 *)&local_1c,param_1);
    sub_0800507A(DAT_03000600,&local_1c,0,0);
    return 0;
  }
  return 0;
}

