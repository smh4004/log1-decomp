/* sub_08000882  (original: 0x08000882-0x080008B4 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002F80();
extern int sub_0800E4F8();
extern int sub_08001FA8();
extern int volatile DAT_03003b6c;
extern undefined1 volatile DAT_0300004c;
extern undefined1 volatile DAT_02029ba0;
extern undefined1 volatile DAT_03000028;


void sub_08000882(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  sub_0800E4F8(&DAT_03000028,&DAT_02029ba0 + param_2 * 0xac,0xa8,param_4,param_4);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - DAT_03003b6c;
  sub_08002F80();
  sub_08001FA8(DAT_0300004c);
  return;
}

