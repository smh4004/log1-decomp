/* sub_0800B18E  (original: 0x0800B18E-0x0800B234 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002716();
extern int sub_08002300();
extern int sub_08000954();
extern int sub_0800507A();
extern int sub_0800245A();
extern int volatile DAT_03000600;
extern undefined * volatile gUnknown_08011E24;


void sub_0800B18E(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_20 (*(undefined4 *)((char *)__frame + 0x0))
#define local_1c (*(undefined4 *)((char *)__frame + 0x4))
#define local_18 (*(undefined4 *)((char *)__frame + 0x8))
#define local_14 (*(undefined4 *)((char *)__frame + 0xc))
  iVar3 = sub_08002716(param_1);
  *(undefined1 *)(iVar3 + 0x14) = *(undefined1 *)(param_1 + 6);
  sub_0800245A(iVar3,&gUnknown_08011E24);
  sVar1 = (short)(*(short *)(param_1 + 8) + *(short *)(param_1 + 0xc)) >> 1;
  sVar5 = (short)(*(short *)(param_1 + 10) + *(short *)(param_1 + 0xe)) >> 1;
  local_20 = CONCAT22(sVar5,sVar1);
  local_18 = local_20;
  sVar6 = *(short *)(iVar3 + 4) >> 1;
  sVar2 = *(short *)(iVar3 + 6) >> 1;
  local_1c = CONCAT22(sVar2,sVar6);
  local_14 = local_1c;
  local_1c = CONCAT22(sVar5 - sVar2,sVar1 - sVar6);
  *(undefined4 *)(iVar3 + 0x20) = local_1c;
  *(int *)(iVar3 + 0x3c) = param_1;
  iVar4 = sub_08000954(param_1);
  if (iVar4 == 0) {
    *(undefined4 *)(iVar3 + 0x38) = 0x800b111;
  }
  else {
    sub_08002300(&local_18,iVar3);
    sub_0800507A(DAT_03000600,(short *)&local_18,0,0);
  }
  return;
}

