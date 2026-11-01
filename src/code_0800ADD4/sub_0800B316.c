/* sub_0800B316  (original: 0x0800B316-0x0800B368 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int WaitForVBlank();
extern int sub_0800E460();
extern int sub_0800AB12();
extern int sub_0800AB00();
extern undefined volatile DAT_02029b94;
extern undefined1 volatile DAT_02029d94;
extern undefined2 volatile REG_IE;


undefined4 sub_0800B316(undefined *param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((param_1 < &DAT_02029b94) || (&DAT_02029d94 < param_2)) {
    uVar2 = 0;
  }
  else {
    uVar3 = (int)(param_1 + -0x2029b94) >> 3;
    sub_0800AB00();
    WaitForVBlank(1);
    uVar1 = REG_IE;
    REG_IE = 0x40;
    for (; (int)uVar3 < (int)(param_2 + -0x2029b8d) >> 3; uVar3 = uVar3 + 1) {
      sub_0800E460(uVar3 & 0xffff,&DAT_02029b94 + uVar3 * 8);
    }
    REG_IE = uVar1;
    sub_0800AB12();
    uVar2 = 1;
  }
  return uVar2;
}

