/* sub_0800DB08  (original: 0x0800DB08-0x0800DBC0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080062C4();
extern int sub_08006D90();
extern int sub_080024B8();
extern int sub_08002810();
extern int sub_080062FC();
extern int sub_080085A0();
extern uint volatile DAT_030005fc;
extern uint volatile DAT_030007e0;
extern undefined4 volatile DAT_03003b48;
extern undefined4 volatile DAT_03003b54;
extern undefined4 volatile DAT_030047f0;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;
extern undefined volatile gUnknown_0815A69C;


void sub_0800DB08(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  
  if ((*(byte *)(param_1 + 4) == DAT_030005fc) &&
     (iVar1 = sub_08002810((uint)*(byte *)(param_1 + 5)), iVar1 != 0)) {
    if (*(char *)(param_1 + 5) == '4') {
      DAT_030007e0 = (uint)(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)];
    }
    else {
      *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 6);
      puVar2 = *(undefined2 **)(iVar1 + 0x3c);
      if (puVar2[0x4e] == 0) {
        sub_080062FC(&DAT_03003b48,(int)puVar2);
      }
      else if (*(char *)((int)puVar2 + 0xb) == '\x02') {
        sub_080062FC(&DAT_03003b54,(int)puVar2);
      }
      else {
        sub_080062FC(&DAT_030047f0,(int)puVar2);
      }
      sub_08006D90(puVar2,2,(uint)(byte)(&gUnknown_0815A69C)[*(byte *)(iVar1 + 0x15)]);
      sub_080062C4(&DAT_030047f0,(int)puVar2,iVar1);
      sub_080085A0((int)puVar2,(short *)(iVar1 + 0x20));
    }
    sub_080024B8(iVar1,(int)(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)]]
                 ,0,0);
  }
  return;
}

