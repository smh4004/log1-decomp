/* sub_08003120  (original: 0x08003120-0x080031E2 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 75% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08006D90();
extern int sub_08002486();
extern int sub_08005C7A();
extern int sub_0800279E();
extern int sub_08002716();
extern int sub_080062C4();
extern int volatile DAT_030007b8;
extern int volatile DAT_030007e0;
extern undefined * volatile gUnknown_08166944;
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;
extern undefined2 * volatile DAT_030046b4;
extern undefined4 volatile DAT_030007d8;
extern undefined4 volatile DAT_030007cc;
extern undefined4 volatile DAT_030007c4;
extern undefined4 volatile DAT_030007d0;
extern undefined4 volatile DAT_030007c8;
extern byte volatile DAT_030007ac;
extern byte volatile DAT_030007b0;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;
extern int volatile DAT_030007bc;
extern undefined4 volatile DAT_030047f0;
extern undefined volatile gUnknown_0816696C;


void sub_08003120(int param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_18;
  
  DAT_030007b8 = sub_08002716(param_1);
  sub_08002486(DAT_030007b8,(int)(&gUnknown_085C0C80)[DAT_030007e0],&gUnknown_0816696C,0);
  local_18 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  *(undefined4 *)(DAT_030007b8 + 0x20) = local_18;
  iVar4 = DAT_030007b8;
  *(undefined4 *)(DAT_030007b8 + 0x38) = 0x8003033;
  puVar2 = DAT_030046b4;
  puVar3 = DAT_030046b4 + 0x13c;
  *(undefined2 **)(iVar4 + 0x3c) = DAT_030046b4;
  DAT_030046b4 = puVar3;
  *(undefined1 *)(iVar4 + 0x15) = 0x34;
  sub_08006D90(puVar2,1,0);
  iVar4 = *(int *)(DAT_030007b8 + 0x3c);
  DAT_030007d8 = *(undefined4 *)(iVar4 + 0x84);
  DAT_030007cc = *(undefined4 *)(iVar4 + 0x50);
  DAT_030007c4 = *(undefined4 *)(iVar4 + 0x58);
  DAT_030007d0 = *(undefined4 *)(iVar4 + 0x4c);
  DAT_030007c8 = *(undefined4 *)(iVar4 + 0x54);
  DAT_030007ac = sub_08005C7A();
  sub_080062C4(&DAT_030047f0,(int)puVar2,DAT_030007b8);
  if (DAT_030007b0 != 0) {
    iVar4 = sub_08002716((uint)DAT_030007b0);
    DAT_030007bc = iVar4;
    *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(DAT_030007b8 + 0x20);
    bVar1 = DAT_030007b0;
    uVar6 = (uint)DAT_030007b0;
    iVar5 = sub_0800279E(iVar4);
    if (iVar5 != 0) {
      DAT_030007bc = iVar4;
      *(byte *)(iVar4 + 0x15) = bVar1;
      sub_08002486(iVar4,(int)(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[uVar6]],
                   &gUnknown_08166944,0);
    }
  }
  return;
}

