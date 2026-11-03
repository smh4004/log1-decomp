/* sub_0800CA74  (original: 0x0800CA74-0x0800CAC8 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r3();
extern int sub_08002466();
extern int sub_080097F8();
extern int volatile DAT_030043a0;
extern undefined volatile _0800F214;


void sub_0800CA74(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  unsigned int __frame[3];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_c (*(undefined * *)((char *)__frame + 0x0))
  iVar1 = __call_via_r3();
  if (((iVar1 != 0) &&
      (uVar2 = (uint)*(byte *)(param_1 + 5),
      *(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0x28) + uVar2 * 0x10) != 0)) &&
     (*(int *)(*(int *)(iVar1 + 0x18) + uVar2 * 0x14) != 0)) {
    DAT_030043a0 = iVar1;
    sub_08002466(iVar1,uVar2);
    local_c = &_0800F214;
    sub_080097F8((int *)&local_c);
  }
  return;
}

