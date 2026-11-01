/* sub_080040F0  (original: 0x080040F0-0x08004112 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005EA6();
extern undefined volatile gUnknown_085C0E5C;


void sub_080040F0(undefined2 *param_1)

{
  undefined1 uVar1;
  
  *param_1 = 8;
  param_1[1] = 8;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 6) = 0x18;
  uVar1 = sub_08005EA6(&gUnknown_085C0E5C);
  *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  return;
}

