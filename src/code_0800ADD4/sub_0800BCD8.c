/* sub_0800BCD8  (original: 0x0800BCD8-0x0800BD8E in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002300();
extern int sub_08004FFA();
extern int sub_0800286A();
extern int sub_08002466();
extern int volatile DAT_03000600;
extern undefined volatile UNK_08011ea8;
extern undefined volatile UNK_08011ec8;


void sub_0800BCD8(int param_1)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  unsigned int __frame[10];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_28 (*(short *)((char *)__frame + 0x0))
#define local_26 (*(undefined2 *)((char *)__frame + 0x2))
#define local_24 (*(undefined2 *)((char *)__frame + 0x4))
#define local_22 (*(undefined2 *)((char *)__frame + 0x6))
#define local_20 (*(short *)((char *)__frame + 0x8))
#define local_1e (*(undefined2 *)((char *)__frame + 0xa))
#define local_1c (*(undefined2 *)((char *)__frame + 0xc))
#define local_1a (*(undefined2 *)((char *)__frame + 0xe))
#define local_18 (*(undefined4 *)((char *)__frame + 0x10))
#define local_14 (*(uint *)((char *)__frame + 0x14))
#define local_10 (*(undefined1 *)((char *)__frame + 0x18))
#define local_c (*(undefined4 *)((char *)__frame + 0x1c))
  psVar3 = *(short **)(param_1 + 0x28);
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *psVar3;
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + psVar3[1];
  *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + psVar3[2];
  *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + psVar3[3];
  sub_08002300((undefined4 *)&local_28,param_1);
  local_20 = local_28;
  local_1e = local_26;
  local_1c = local_24;
  local_1a = local_22;
  local_18 = *(undefined4 *)(param_1 + 0x24);
  local_14 = (uint)(*(char *)(param_1 + 0x16) != '\0');
  local_10 = 1;
  local_c = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x3c);
  sub_0800286A(1,&local_20);
  iVar2 = sub_08004FFA(DAT_03000600,&local_20,2);
  if (iVar2 == 0) {
    *(undefined **)(param_1 + 0x28) = &UNK_08011ec8 + (uint)*(byte *)(param_1 + 0x13) * 8;
    sub_08002466(param_1,2);
  }
  else {
    bVar1 = *(char *)(param_1 + 0x10) + 1;
    *(byte *)(param_1 + 0x10) = bVar1;
    if (0xf < bVar1) {
      *(undefined **)(param_1 + 0x28) = &UNK_08011ea8 + (uint)*(byte *)(param_1 + 0x13) * 8;
      sub_08002466(param_1,2);
    }
  }
  return;
}

