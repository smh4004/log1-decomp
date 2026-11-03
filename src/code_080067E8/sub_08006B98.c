/* sub_08006B98  (original: 0x08006B98-0x08006C88 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08006A72();
extern int sub_0800245A();
extern int sub_08002466();
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;
extern undefined volatile DAT_08011670;
extern undefined volatile DAT_08011674;
extern undefined volatile DAT_08011678;
extern undefined * volatile gUnknown_0801167C;


void sub_08006B98(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_20 (*(undefined4 *)((char *)__frame + 0x0))
#define local_1c (*(undefined4 *)((char *)__frame + 0x4))
#define local_18 (*(undefined4 *)((char *)__frame + 0x8))
  local_1c = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  local_18 = local_1c;
  sVar1 = (DAT_030007c0 >> 4) - *(short *)(param_1 + 0x20);
  sVar2 = (DAT_030007c2 >> 4) - *(short *)(param_1 + 0x22);
  local_20 = CONCAT22(sVar2,sVar1);
  local_1c = local_20;
  iVar3 = (int)sVar1 * (int)sVar1 + (int)sVar2 * (int)sVar2;
  if (iVar3 < 0x1901) {
    if (iVar3 < 100) {
      sub_08002466(param_1,0);
    }
    else {
      uVar4 = (uint)*(byte *)(param_1 + 0x13);
      if (((int)(char)(&DAT_08011674)[uVar4] *
           (int)*(short *)((int)&local_1c + (uint)(byte)(&DAT_08011670)[uVar4] * 2) < 1) ||
         (iVar3 = sub_08006A72(param_1,uVar4), iVar3 == 0)) {
        iVar3 = (int)(*(undefined2 *)((char *)&local_1c + 2)) * (int)(*(undefined2 *)((char *)&local_1c + 2));
        iVar5 = (int)(short)local_1c * (int)(short)local_1c;
        uVar4 = (uint)(iVar3 - iVar5 != 0 && iVar5 <= iVar3);
        iVar3 = uVar4 * 2;
        iVar3 = sub_08006A72(param_1,(uint)(byte)(&DAT_08011678)
                                                 [(uint)(0 < *(short *)((int)&local_1c + iVar3)) +
                                                  iVar3]);
        if (iVar3 == 0) {
          iVar3 = (uVar4 ^ 1) * 2;
          sub_08006A72(param_1,(uint)(byte)(&DAT_08011678)
                                           [(uint)(0 < *(short *)((int)&local_1c + iVar3)) + iVar3])
          ;
        }
      }
    }
  }
  else {
    sub_0800245A(param_1,&gUnknown_0801167C);
  }
  return;
}

