/* sub_0800F6A0  (original: 0x0800F6A0-0x0800F774 in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: equal, stack-garbage:mem@03000000.
 */
#include "ghidra_types.h"
extern int sub_08005CA8();
extern int sub_08006F1A();
extern int sub_0800F404();
extern int sub_0800F420();
extern int sub_0800F3F0();
extern int sub_0800F3E4();
extern int sub_0800F358();
extern short volatile DAT_03003b38;
extern short volatile DAT_03003b3a;
extern short volatile DAT_03003b3c;
extern short volatile DAT_03003b3e;


void sub_0800F6A0(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  unsigned int __frame[14];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_38 (*(undefined4 *)((char *)__frame + 0x0))
#define asStack_34 ((short *)((char *)__frame + 0x4))
#define asStack_2c ((short *)((char *)__frame + 0xc))
#define local_24 (*(short *)((char *)__frame + 0x14))
#define local_22 (*(short *)((char *)__frame + 0x16))
#define iStack_20 (*(int *)((char *)__frame + 0x18))
#define local_1c (*(undefined4 *)((char *)__frame + 0x1c))
#define uStack_18 (*(undefined4 *)((char *)__frame + 0x20))
  if (*(int *)(param_1 + 0xac) + -1 <= *(int *)(param_1 + 0xa8)) {
    iVar4 = (int)*(short *)(param_1 + 0x48);
    if (0xe < iVar4) {
      iVar4 = 0xe;
    }
    if (0 < iVar4) {
      iStack_20 = param_1;
      local_1c = param_2;
      uStack_18 = param_3;
      sVar2 = sub_08005CA8(iVar4);
      sVar3 = sub_08005CA8(iVar4);
      sVar1 = (short)(iVar4 >> 1);
      sub_0800F3E4(&local_24,(sVar1 - sVar2) + (short)local_1c,(sVar1 - sVar3) + (short)param_3);
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
      sub_0800F420(asStack_34,(byte *)(param_1 + 0x28),(short *)&local_38);
      sub_0800F3F0(asStack_2c,asStack_34);
      iVar4 = sub_0800F358(asStack_2c,0);
      if (iVar4 != 0) {
        sub_08006F1A(param_1,&local_24,0);
      }
    }
  }
  return;
}

