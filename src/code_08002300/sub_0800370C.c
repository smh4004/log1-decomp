/* sub_0800370C  (original: 0x0800370C-0x08003750 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009064();
extern undefined2 volatile DAT_02029d9e;
extern undefined2 volatile DAT_02029da0;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile _08003980;


void sub_0800370C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 == '\0') {
    param_1 = (*(byte *)(param_1 + 4) + 1) - (uint)*(byte *)(param_1 + 5);
    cVar1 = '\x01';
    DAT_02029d9e = 1;
    DAT_02029da0 = (undefined2)param_1;
  }
  else if (cVar1 == '\x01') {
    param_1 = *(byte *)(param_1 + 6) + 1;
    cVar1 = '\r';
    DAT_02029d9e = 0xd;
    DAT_02029da0 = (undefined2)param_1;
  }
  else if (cVar1 == '\x02') {
    DAT_02029d9e = 0x19;
    param_1 = 0xf;
    DAT_02029da0 = 0xf;
  }
  sub_08009064(&DAT_02029d94,&_08003980,param_1,cVar1,param_4);
  return;
}

