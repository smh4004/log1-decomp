/* sub_080032C8  (original: 0x080032C8-0x08003398 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800F3C4();
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;
extern int volatile DAT_030007b8;
extern undefined2 volatile gUnknown_08010840;


void sub_080032C8(short *param_1)

{
  char cVar1;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(undefined4 *)((char *)__frame + 0x0))
#define local_14 (*(undefined4 *)((char *)__frame + 0x4))
#define sStack_10 (*(short *)((char *)__frame + 0x8))
#define sStack_e (*(short *)((char *)__frame + 0xa))
  local_18 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  local_14 = local_18;
  sub_0800F3C4((short *)&local_14,&gUnknown_08010840);
  cVar1 = *(char *)(DAT_030007b8 + 0x13);
  if (cVar1 == '\0') {
    *param_1 = (short)local_14 + 4;
    param_1[1] = sStack_e + 2;
    param_1[2] = sStack_10 + -4;
    param_1[3] = sStack_e + 4;
  }
  else if (cVar1 == '\x01') {
    *param_1 = (short)local_14 + 4;
    param_1[1] = (*(undefined2 *)((char *)&local_14 + 2)) + -4;
    param_1[2] = sStack_10 + -4;
    param_1[3] = (*(undefined2 *)((char *)&local_14 + 2)) + -2;
  }
  else if ((cVar1 == '\x02') || (cVar1 != '\x03')) {
    *param_1 = (short)local_14 + -4;
    param_1[1] = (*(undefined2 *)((char *)&local_14 + 2)) + 2;
    param_1[2] = (short)local_14 + -2;
    param_1[3] = sStack_e + -2;
  }
  else {
    *param_1 = sStack_10 + 2;
    param_1[1] = (*(undefined2 *)((char *)&local_14 + 2)) + 2;
    param_1[2] = sStack_10 + 4;
    param_1[3] = sStack_e + -2;
  }
  return;
}

