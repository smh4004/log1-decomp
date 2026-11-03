/* sub_0800573A  (original: 0x0800573A-0x080057A8 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080062C4();
extern int sub_08006D90();
extern int sub_080085A0();
extern int sub_08002486();
extern int sub_0800236E();
extern int sub_0800507A();
extern int volatile DAT_03000600;
extern undefined * volatile gUnknown_081667F0;
extern undefined2 * volatile DAT_030046b4;
extern undefined4 volatile DAT_030047f0;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;
extern undefined volatile gUnknown_0815A69C;


void sub_0800573A(int param_1)

{
  undefined2 *puVar1;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_18 ((short *)((char *)__frame + 0x0))
  sub_0800236E((undefined4 *)asStack_18,param_1);
  sub_0800507A(DAT_03000600,asStack_18,1,0);
  puVar1 = DAT_030046b4;
  DAT_030046b4 = DAT_030046b4 + 0x13c;
  sub_08006D90(puVar1,2,(uint)(byte)(&gUnknown_0815A69C)[*(byte *)(param_1 + 0x15)]);
  sub_080062C4(&DAT_030047f0,(int)puVar1,param_1);
  *(undefined2 **)(param_1 + 0x3c) = puVar1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  sub_08002486(param_1,(int)(&gUnknown_085C0C80)
                            [(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 0x15)]],
               &gUnknown_081667F0,0);
  *(undefined4 *)(param_1 + 0x38) = 0x8005605;
  sub_080085A0((int)puVar1,(short *)(param_1 + 0x20));
  return;
}

