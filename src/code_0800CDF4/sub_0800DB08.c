/* sub_0800DB08  (original: 0x0800DB08-0x0800DBC0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002810();
extern int sub_080062FC();
extern int sub_080085A0();
extern int sub_080062C4();
extern int sub_08006D90();
extern int sub_080024B8();
extern uint volatile DAT_030005fc;
extern uint volatile DAT_030007e0;
extern undefined4 volatile DAT_03003b48;
extern undefined4 volatile DAT_03003b54;
extern undefined4 volatile DAT_030047f0;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;
extern undefined volatile gUnknown_0815A69C;


void sub_0800DB08(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 4) == DAT_030005fc) &&
     (iVar1 = sub_08002810(*(undefined1 *)(param_1 + 5)), iVar1 != 0)) {
    if (*(char *)(param_1 + 5) == '4') {
      DAT_030007e0 = (uint)(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)];
    }
    else {
      *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 6);
      iVar2 = *(int *)(iVar1 + 0x3c);
      if (*(short *)(iVar2 + 0x9c) == 0) {
        sub_080062FC(&DAT_03003b48,iVar2);
      }
      else if (*(char *)(iVar2 + 0xb) == '\x02') {
        sub_080062FC(&DAT_03003b54,iVar2);
      }
      else {
        sub_080062FC(&DAT_030047f0,iVar2);
      }
      sub_08006D90(iVar2,2,(&gUnknown_0815A69C)[*(byte *)(iVar1 + 0x15)]);
      sub_080062C4(&DAT_030047f0,iVar2,iVar1);
      sub_080085A0(iVar2,iVar1 + 0x20);
    }
    sub_080024B8(iVar1,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)]],0,0,
                 param_4);
  }
  return;
}

