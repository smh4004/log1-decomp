/* sub_08004A76  (original: 0x08004A76-0x08004AB0 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08000926();
extern int sub_08004E98();
extern undefined1 volatile DAT_0300004e;
extern undefined * volatile gUnknown_085C2FB8;


void sub_08004A76(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000926(0x3000028,(uint)*(byte *)(param_1 + 4));
  if (iVar1 == 0) {
    sub_08004E98(0x3000864,(int)(&gUnknown_085C2FB8)[*(byte *)(param_1 + 4)]);
    (&DAT_0300004e)[*(byte *)(param_1 + 4)] = (&DAT_0300004e)[*(byte *)(param_1 + 4)] + '\x01';
  }
  return;
}

