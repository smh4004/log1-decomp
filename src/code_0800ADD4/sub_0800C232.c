/* sub_0800C232  (original: 0x0800C232-0x0800C266 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800FE0C();
extern int sub_08002466();


void sub_0800C232(int param_1,int param_2)

{
  int iVar1;
  unsigned int __frame[2];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_8 ((int *)((char *)__frame + 0x0))
  if (*(char *)(param_2 + 0x15) != -1) {
    local_8[0] = param_2;
    iVar1 = sub_0800FE0C((int *)(param_1 + 4),local_8);
    *(undefined1 *)(local_8[0] + 0xd) = *(undefined1 *)(iVar1 + 0x11);
    if (*(int *)(iVar1 + 0x14) == 0) {
      *(undefined4 *)(local_8[0] + 0x18) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(local_8[0] + 0x38) = *(undefined4 *)(iVar1 + 0xc);
      sub_08002466(local_8[0],(uint)*(byte *)(iVar1 + 0x10));
    }
  }
  return;
}

