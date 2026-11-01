/* sub_0800F6A0  (original: 0x0800F6A0-0x0800F774 in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800F3E4();
extern int sub_0800F3F0();
extern int sub_0800F420();
extern int sub_0800F358();
extern int sub_0800F404();
extern int sub_08006F1A();
extern int sub_08005CA8();
extern short volatile DAT_03003b38;
extern short volatile DAT_03003b3a;
extern short volatile DAT_03003b3c;
extern short volatile DAT_03003b3e;


void sub_0800F6A0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  unsigned int __frame[14];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_38 (*(undefined4 *)((char *)__frame + 0x0))
#define auStack_34 ((undefined1 *)((char *)__frame + 0x4))
#define auStack_2c ((undefined1 *)((char *)__frame + 0xc))
#define local_24 (*(short *)((char *)__frame + 0x14))
#define local_22 (*(short *)((char *)__frame + 0x16))
#define iStack_20 (*(int *)((char *)__frame + 0x18))
#define local_1c (*(int *)((char *)__frame + 0x1c))
#define iStack_18 (*(int *)((char *)__frame + 0x20))
  if (*(int *)(param_1 + 0xac) + -1 <= *(int *)(param_1 + 0xa8)) {
    iVar3 = (int)*(short *)(param_1 + 0x48);
    if (0xe < iVar3) {
      iVar3 = 0xe;
    }
    if (0 < iVar3) {
      iStack_20 = param_1;
      local_1c = param_2;
      iStack_18 = param_3;
      iVar1 = sub_08005CA8(iVar3);
      iVar2 = sub_08005CA8(iVar3);
      sub_0800F3E4(&local_24,((iVar3 >> 1) - iVar1) + local_1c,((iVar3 >> 1) - iVar2) + param_3);
      if (local_24 < DAT_03003b38) {
        local_24 = DAT_03003b38;
      }
      if (local_22 < DAT_03003b3a) {
        local_22 = DAT_03003b3a;
      }
      if (DAT_03003b3c < local_24) {
        local_24 = DAT_03003b3c;
      }
      if (DAT_03003b3e < local_22) {
        local_22 = DAT_03003b3e;
      }
      local_38 = sub_0800F404(&local_24,3);
      sub_0800F420(auStack_34,param_1 + 0x28,&local_38);
      sub_0800F3F0(auStack_2c,auStack_34);
      iVar3 = sub_0800F358(auStack_2c,0);
      if (iVar3 != 0) {
        sub_08006F1A(param_1,&local_24,0);
      }
    }
  }
  return;
}

