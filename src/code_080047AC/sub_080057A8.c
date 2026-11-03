/* sub_080057A8  (original: 0x080057A8-0x08005840 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 55% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800573A();
extern int sub_0800994C();
extern int sub_08005478();
extern int sub_0800236E();
extern int sub_08003398();
extern int sub_080051D0();
extern int volatile DAT_030007b8;
extern undefined volatile DAT_03000076;


undefined4 sub_080057A8(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_20 ((short *)((char *)__frame + 0x0))
#define sStack_18 (*(short *)((char *)__frame + 0x8))
#define sStack_16 (*(short *)((char *)__frame + 0xa))
#define sStack_14 (*(short *)((char *)__frame + 0xc))
#define sStack_12 (*(short *)((char *)__frame + 0xe))
#define local_10 (*(undefined4 *)((char *)__frame + 0x10))
  if (param_2 == 0) {
    sub_0800236E((undefined4 *)asStack_20,param_1);
    sub_0800994C(&sStack_18,asStack_20,2);
    uVar1 = sub_08003398();
    (*(undefined2 *)((char *)&local_10 + 0)) = (short)uVar1;
    if ((((sStack_18 <= (short)local_10) && ((short)local_10 < sStack_14)) &&
        ((*(undefined2 *)((char *)&local_10 + 2)) = (short)((uint)uVar1 >> 0x10), sStack_16 <= (*(undefined2 *)((char *)&local_10 + 2)))) &&
       ((*(undefined2 *)((char *)&local_10 + 2)) < sStack_12)) {
      *(byte *)(param_1 + 0x13) = *(byte *)(DAT_030007b8 + 0x13) ^ 1;
      local_10 = uVar1;
      iVar2 = sub_08005478(0,(uint)*(byte *)(param_1 + 0x15));
      if (iVar2 != 0) {
        return 1;
      }
      sub_080051D0((uint)*(byte *)(param_1 + 0x16),&DAT_03000076 + *(byte *)(param_1 + 0x16));
      return 1;
    }
  }
  else if ((param_2 == 2) && (*(byte *)(param_1 + 0x15) == param_3)) {
    sub_0800573A(param_1);
  }
  return 0;
}

