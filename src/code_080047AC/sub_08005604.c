/* sub_08005604  (original: 0x08005604-0x0800573A in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 50% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800507A();
extern int sub_0800A714();
extern int sub_08007416();
extern int sub_08002466();
extern int sub_08003446();
extern int sub_0800236E();
extern int sub_08002396();
extern int volatile DAT_030007b8;
extern int volatile DAT_03003b6c;
extern int volatile DAT_030007cc;
extern int volatile DAT_03000600;


undefined2 sub_08005604(int param_1,int param_2,short *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define sStack_20 (*(short *)((char *)__frame + 0x0))
#define sStack_1e (*(short *)((char *)__frame + 0x2))
#define sStack_1c (*(short *)((char *)__frame + 0x4))
#define sStack_1a (*(short *)((char *)__frame + 0x6))
#define uStack_18 (*(undefined4 *)((char *)__frame + 0x8))
  if (param_2 == 0) {
    iVar3 = *(int *)(param_1 + 0x3c);
    if (*(short *)(iVar3 + 0x9c) == 0) {
      return 0;
    }
    sub_08002396(&sStack_20,param_1);
    uVar1 = sub_08003446();
    iVar2 = DAT_030007b8;
    (*(undefined2 *)((char *)&uStack_18 + 0)) = (short)uVar1;
    if (((sStack_20 <= (short)uStack_18) && ((short)uStack_18 < sStack_1c)) &&
       (((*(undefined2 *)((char *)&uStack_18 + 2)) = (short)((uint)uVar1 >> 0x10), sStack_1e <= (*(undefined2 *)((char *)&uStack_18 + 2)) &&
        ((*(undefined2 *)((char *)&uStack_18 + 2)) < sStack_1a)))) {
      *(byte *)(param_1 + 0x13) = *(byte *)(DAT_030007b8 + 0x13) ^ 1;
      uStack_18 = uVar1;
      sub_08002466(iVar2,3 - ((DAT_03003b6c << 0x1f) >> 0x1f));
      iVar2 = sub_0800A714(0x80);
      sub_08007416(*(int *)(DAT_030007b8 + 0x3c),iVar3,0,(uint)((iVar2 + 0x180) * DAT_030007cc) >> 9
                  );
      return 1;
    }
  }
  else if (param_2 == 1) {
    iVar3 = *(int *)(param_1 + 0x3c);
    if (*(short *)(iVar3 + 0x9c) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 6) != 0) {
      return 0;
    }
    sub_08002396(&sStack_1c,param_1);
    if ((((sStack_1c < param_3[2]) && (*param_3 < (short)uStack_18)) && (sStack_1a < param_3[3])) &&
       (param_3[1] < (*(undefined2 *)((char *)&uStack_18 + 2)))) {
      if (((char)param_3[8] == '\0') || (*(short *)(iVar3 + 0x14) < 1)) {
        sub_08007416(*(int *)(param_3 + 10),iVar3,1,*(int *)(param_3 + 4));
      }
      return 1;
    }
  }
  else if (param_2 == 5) {
    sub_0800236E((undefined4 *)&sStack_1c,param_1);
    sub_0800507A(DAT_03000600,&sStack_1c,1,0);
  }
  else if (param_2 == 3) {
    return 1;
  }
  return 0;
}

