/* sub_08006C9A  (original: 0x08006C9A-0x08006D56 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800245A();
extern int sub_08002466();
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;
extern int volatile DAT_030007dc;
extern undefined * volatile PTR_sub_0800AEF8_1_08011690;


void sub_08006C9A(int param_1)

{
  short sVar1;
  short sVar2;
  
  sVar1 = (DAT_030007c0 >> 4) - *(short *)(param_1 + 0x20);
  sVar2 = (DAT_030007c2 >> 4) - *(short *)(param_1 + 0x22);
  if ((int)sVar1 * (int)sVar1 + (int)sVar2 * (int)sVar2 < 0x10) {
    if (DAT_030007dc == 0) {
      sub_08002466(param_1,0);
    }
    else {
      sub_0800245A(param_1,&PTR_sub_0800AEF8_1_08011690);
    }
  }
  else {
    if (sVar2 < 2) {
      if (sVar2 + 1 < 0 != SCARRY4((int)sVar2,1)) {
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + -3;
        *(undefined1 *)(param_1 + 0x13) = 1;
      }
    }
    else {
      *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + 3;
      *(undefined1 *)(param_1 + 0x13) = 0;
    }
    if (sVar1 < 2) {
      if (sVar1 + 1 < 0 != SCARRY4((int)sVar1,1)) {
        *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + -3;
        *(undefined1 *)(param_1 + 0x13) = 2;
      }
    }
    else {
      *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 3;
      *(undefined1 *)(param_1 + 0x13) = 3;
    }
  }
  return;
}

