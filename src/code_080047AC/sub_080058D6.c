/* sub_080058D6  (original: 0x080058D6-0x0800599A in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 48% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800573A();
extern int sub_08002486();
extern int sub_08002716();
extern undefined1 volatile DAT_03000038;
extern undefined * volatile gUnknown_085C2614;
extern undefined volatile gUnknown_08543988;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;


int sub_080058D6(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)(byte)(&gUnknown_08543988)[(ushort)param_1[3]];
  if (*(char *)((int)param_1 + 5) == '\x01') {
    if (((&DAT_03000038)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7))) != 0) {
      return 0;
    }
  }
  else if ((*(char *)((int)param_1 + 5) == '\x02') &&
          (((&DAT_03000038)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7))) == 0)) {
    return 0;
  }
  iVar3 = sub_08002716();
  *(undefined2 *)(iVar3 + 0x20) = *param_1;
  *(undefined2 *)(iVar3 + 0x22) = param_1[1];
  *(undefined1 *)(iVar3 + 0x15) = *(undefined1 *)(param_1 + 2);
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\0') {
    sub_08002486(iVar3,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 2)]],
                 &gUnknown_085C2614,0);
    *(undefined1 *)(iVar3 + 0x16) = *(undefined1 *)((int)param_1 + 9);
    *(undefined1 *)(iVar3 + 0x14) = *(undefined1 *)(param_1 + 5);
    *(undefined4 *)(iVar3 + 0x38) = 0x8005841;
  }
  else if (cVar1 == '\x01') {
    sub_08002486(iVar3,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 2)]],
                 &gUnknown_085C2614,0);
    *(undefined1 *)(iVar3 + 0x16) = *(undefined1 *)((int)param_1 + 9);
    *(undefined4 *)(iVar3 + 0x38) = 0x80057a9;
  }
  else if (cVar1 == '\x02') {
    sub_0800573A(iVar3);
  }
  return iVar3;
}

