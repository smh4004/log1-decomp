/* sub_08003398  (original: 0x08003398-0x08003446 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0.
 */
#include "ghidra_types.h"
extern int sub_0800F3C4();
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;
extern int volatile DAT_030007b8;
extern undefined2 volatile gUnknown_08010840;


undefined4 sub_08003398(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define uStack_20 (*(undefined4 *)((char *)__frame + 0x0))
#define local_1c (*(undefined4 *)((char *)__frame + 0x4))
#define local_10 (*(undefined4 *)((char *)__frame + 0x10))
#define local_c (*(undefined4 *)((char *)__frame + 0x14))
#define local_8 (*(short *)((char *)__frame + 0x18))
#define local_6 (*(short *)((char *)__frame + 0x1a))
  local_10 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  local_c = local_10;
  sub_0800F3C4((short *)&local_c,&gUnknown_08010840);
  sVar2 = (short)((short)local_c + local_8) >> 1;
  sVar3 = (short)((*(undefined2 *)((char *)&local_c + 2)) + local_6) >> 1;
  cVar1 = *(char *)(DAT_030007b8 + 0x13);
  if (cVar1 == '\0') {
    local_1c = CONCAT22(local_6 + 2,sVar2);
  }
  else if (cVar1 == '\x01') {
    local_1c = CONCAT22((*(undefined2 *)((char *)&local_c + 2)) + -2,sVar2);
  }
  else if ((cVar1 == '\x02') || (cVar1 != '\x03')) {
    uStack_20 = CONCAT22(sVar3,(short)local_c + -2);
    local_1c = uStack_20;
  }
  else {
    local_1c = CONCAT22(sVar3,local_8 + 2);
  }
#define local_1c (*(return *)((char *)__frame + 0x4))
}

