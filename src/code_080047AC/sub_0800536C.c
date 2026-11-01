/* sub_0800536C  (original: 0x0800536C-0x08005380 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080051D0();
extern undefined volatile DAT_03000076;


void sub_0800536C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (&DAT_03000076)[param_1] = (char)param_2;
  sub_080051D0(param_1,&DAT_03000076 + param_1,param_2,0x4e,param_4);
  return;
}

