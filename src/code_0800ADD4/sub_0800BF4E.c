/* sub_0800BF4E  (original: 0x0800BF4E-0x0800C010 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 8/8 snapshots, 94% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002300();
extern int sub_08004FFA();
extern int sub_0800236E();
extern int sub_0800283C();
extern int sub_08002466();
extern short volatile DAT_0300060c;
extern short volatile DAT_03000608;
extern short volatile DAT_0300060e;
extern short volatile DAT_0300060a;
extern int volatile DAT_03000600;


void sub_0800BF4E(int param_1)

{
  int iVar1;
  unsigned int __frame[11];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_2c (*(short *)((char *)__frame + 0x0))
#define local_2a (*(undefined2 *)((char *)__frame + 0x2))
#define local_28 (*(undefined2 *)((char *)__frame + 0x4))
#define local_26 (*(undefined2 *)((char *)__frame + 0x6))
#define local_24 (*(short *)((char *)__frame + 0x8))
#define local_22 (*(undefined2 *)((char *)__frame + 0xa))
#define local_20 (*(undefined2 *)((char *)__frame + 0xc))
#define local_1e (*(undefined2 *)((char *)__frame + 0xe))
#define local_1c (*(undefined4 *)((char *)__frame + 0x10))
#define local_18 (*(uint *)((char *)__frame + 0x14))
#define local_14 (*(ushort *)((char *)__frame + 0x18))
#define sStack_12 (*(short *)((char *)__frame + 0x1a))
#define local_10 (*(undefined4 *)((char *)__frame + 0x1c))
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(param_1 + 0x28);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(param_1 + 0x2a);
  sub_08002300((undefined4 *)&local_14,param_1);
  if (((((short)local_14 < DAT_0300060c) && (DAT_03000608 < (short)local_10)) &&
      (sStack_12 < DAT_0300060e)) && (DAT_0300060a < (*(undefined2 *)((char *)&local_10 + 2)))) {
    sub_0800236E((undefined4 *)&local_2c,param_1);
    local_24 = local_2c;
    local_22 = local_2a;
    local_20 = local_28;
    local_1e = local_26;
    local_1c = *(undefined4 *)(param_1 + 0x2c);
    local_18 = (uint)(*(char *)(param_1 + 0x16) != '\0');
    local_14 = local_14 & 0xff00;
    local_10 = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x3c);
    iVar1 = sub_0800283C(1,&local_24);
    if ((iVar1 != 0) || (iVar1 = sub_08004FFA(DAT_03000600,&local_24,2), iVar1 == 0)) {
      sub_08002466(param_1,2);
    }
  }
  else {
    sub_08002466(param_1,2);
  }
  return;
}

