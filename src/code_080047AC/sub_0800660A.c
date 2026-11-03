/* sub_0800660A  (original: 0x0800660A-0x08006798 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 10% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800A724();
extern int sub_08004FFA();
extern int sub_08002E42();
extern int sub_0800A714();
extern int sub_0800236E();
extern int sub_0800507A();
extern int sub_08002466();
extern int volatile DAT_03000600;


void sub_0800660A(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  short sVar5;
  short sVar6;
  short *psVar7;
  unsigned int __frame[11];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define uStack_2c (*(undefined4 *)((char *)__frame + 0x0))
#define local_24 (*(undefined4 *)((char *)__frame + 0x8))
#define local_20 (*(undefined4 *)((char *)__frame + 0xc))
#define local_1c (*(undefined4 *)((char *)__frame + 0x10))
#define local_18 (*(undefined4 *)((char *)__frame + 0x14))
  if (((*(int *)(*(int *)(*(int *)(param_1 + 0x1c) + 0x28) + 0x10) != 0) &&
      (*(int *)(*(int *)(param_1 + 0x18) + 0x14) != 0)) && (iVar2 = sub_0800A724(300), iVar2 != 0))
  {
    psVar7 = (short *)(param_1 + 0x2c);
    sub_0800236E(&local_1c,param_1);
    *psVar7 = (short)local_1c;
    *(short *)(param_1 + 0x2e) = (*(undefined2 *)((char *)&local_1c + 2));
    *(short *)(param_1 + 0x30) = (short)local_18;
    *(short *)(param_1 + 0x32) = (*(undefined2 *)((char *)&local_18 + 2));
    iVar2 = sub_0800A714(4);
    puVar4 = (undefined2 *)(param_1 + 0x28);
    if (iVar2 == 0) {
      sVar6 = *(short *)(param_1 + 0x2e) + 8;
      uStack_2c = CONCAT22(sVar6,*psVar7);
      local_24 = uStack_2c;
      uVar1 = *(undefined2 *)(param_1 + 0x30);
      sVar5 = *(short *)(param_1 + 0x32) + 8;
      uStack_2c = CONCAT22(sVar5,uVar1);
      local_20 = uStack_2c;
      local_1c = CONCAT22(sVar6,*psVar7);
      local_18 = CONCAT22(sVar5,uVar1);
      *puVar4 = 0;
      *(undefined2 *)(param_1 + 0x2a) = 1;
    }
    else if (iVar2 == 1) {
      sVar5 = *(short *)(param_1 + 0x2e) + -8;
      uStack_2c = CONCAT22(sVar5,*psVar7);
      uVar1 = *(undefined2 *)(param_1 + 0x30);
      local_24 = uStack_2c;
      sVar6 = *(short *)(param_1 + 0x32) + -8;
      uStack_2c = CONCAT22(sVar6,uVar1);
      local_20 = uStack_2c;
      local_1c = CONCAT22(sVar5,*psVar7);
      local_18 = CONCAT22(sVar6,uVar1);
      *puVar4 = 0;
      *(undefined2 *)(param_1 + 0x2a) = 0xffff;
    }
    else if (iVar2 == 2) {
      local_20 = 8;
      local_24 = CONCAT22(*(undefined2 *)(param_1 + 0x2e),*psVar7 + -8);
      local_1c = local_24;
      local_18 = CONCAT22(*(undefined2 *)(param_1 + 0x32),*(undefined2 *)(param_1 + 0x2c));
      *puVar4 = 0xffff;
      *(undefined2 *)(param_1 + 0x2a) = 0;
    }
    else if (iVar2 == 3) {
      local_1c = CONCAT22(*(undefined2 *)(param_1 + 0x2e),*(undefined2 *)(param_1 + 0x30));
      local_20 = 8;
      local_24 = CONCAT22(*(undefined2 *)(param_1 + 0x32),*(short *)(param_1 + 0x30) + 8);
      local_18 = local_24;
      *puVar4 = 1;
      *(undefined2 *)(param_1 + 0x2a) = 0;
    }
    iVar3 = sub_08004FFA(DAT_03000600,(short *)&local_1c,0);
    if ((iVar3 != 0) &&
       (((sub_08002E42(&local_24), (short)local_18 <= (short)local_24 ||
         ((short)local_20 <= (short)local_1c)) ||
        (((*(undefined2 *)((char *)&local_18 + 2)) <= (*(undefined2 *)((char *)&local_24 + 2)) || ((*(undefined2 *)((char *)&local_20 + 2)) <= (*(undefined2 *)((char *)&local_1c + 2)))))))) {
      *(char *)(param_1 + 0x13) = (char)iVar2;
      sub_0800507A(DAT_03000600,(short *)&local_1c,0,0);
      sub_08002466(param_1,1);
    }
  }
  return;
}

