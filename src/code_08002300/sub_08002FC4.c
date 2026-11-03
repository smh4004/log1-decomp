/* sub_08002FC4  (original: 0x08002FC4-0x08002FF6 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002486();
extern int sub_0800279E();
extern byte volatile DAT_030007b0;
extern int volatile DAT_030007bc;
extern undefined * volatile gUnknown_08166944;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;


void sub_08002FC4(int param_1,int param_2)

{
  int iVar1;
  
  DAT_030007b0 = (char)param_1;
  iVar1 = sub_0800279E(param_2);
  if (iVar1 != 0) {
    DAT_030007bc = param_2;
    *(char *)(param_2 + 0x15) = (char)param_1;
    sub_08002486(param_2,(int)(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[param_1]],
                 &gUnknown_08166944,0);
  }
  return;
}

