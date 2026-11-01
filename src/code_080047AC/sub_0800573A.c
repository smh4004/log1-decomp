/* sub_0800573A  (original: 0x0800573A-0x080057A8 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080062C4();
extern int sub_080085A0();
extern int sub_08006D90();
extern int sub_0800507A();
extern int sub_08002486();
extern int sub_0800236E();
extern undefined4 volatile DAT_03000600;
extern undefined * volatile gUnknown_081667F0;
extern int volatile DAT_030046b4;
extern undefined4 volatile DAT_030047f0;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;
extern undefined volatile gUnknown_0815A69C;


void sub_0800573A(int param_1)

{
  int iVar1;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_18 ((undefined1 *)((char *)__frame + 0x0))
  sub_0800236E(auStack_18,param_1);
  sub_0800507A(DAT_03000600,auStack_18,1,0);
  iVar1 = DAT_030046b4;
  DAT_030046b4 = DAT_030046b4 + 0x278;
  sub_08006D90(iVar1,2,(&gUnknown_0815A69C)[*(byte *)(param_1 + 0x15)]);
  sub_080062C4(&DAT_030047f0,iVar1,param_1);
  *(int *)(param_1 + 0x3c) = iVar1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  sub_08002486(param_1,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 0x15)]],
               &gUnknown_081667F0,0);
  *(undefined4 *)(param_1 + 0x38) = 0x8005605;
  sub_080085A0(iVar1,param_1 + 0x20);
  return;
}

