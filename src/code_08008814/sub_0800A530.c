/* sub_0800A530  (original: 0x0800A530-0x0800A54E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800A80E();
extern undefined volatile DAT_0203f040;


void sub_0800A530(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    sub_0800A80E((int *)(&DAT_0203f040 + iVar1 * 0x40),param_1,param_2);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xf);
  return;
}

