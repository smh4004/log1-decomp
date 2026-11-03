/* sub_0800C266  (original: 0x0800C266-0x0800C2B2 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 5/5 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800FE0C();
extern int sub_08002466();
extern int volatile DAT_03000610;
extern undefined4 volatile DAT_03000614;


void sub_0800C266(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(int *)((char *)__frame + 0x0))
  iVar1 = DAT_03000610;
  iVar3 = 0;
  if (0 < DAT_03000610) {
    do {
      local_18 = (&DAT_03000614)[iVar3];
      if (*(char *)(local_18 + 0x15) != -1) {
        iVar2 = sub_0800FE0C((int *)(param_1 + 4),&local_18);
        *(undefined1 *)(local_18 + 0xd) = *(undefined1 *)(iVar2 + 0x11);
        if (*(int *)(iVar2 + 0x14) == 0) {
          *(undefined4 *)(local_18 + 0x18) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(local_18 + 0x38) = *(undefined4 *)(iVar2 + 0xc);
          sub_08002466(local_18,(uint)*(byte *)(iVar2 + 0x10));
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

