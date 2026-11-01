/* sub_0800426E  (original: 0x0800426E-0x0800428E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 50% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800245A();
extern undefined volatile gUnknown_0801144C;


undefined4 sub_0800426E(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 4) {
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x34);
    sub_0800245A(param_1,&gUnknown_0801144C,param_3,param_4,param_4);
  }
  else if (param_2 == 5) {
    sub_0800245A(param_1,*(undefined4 *)(param_1 + 0x3c),param_3,param_4,param_4);
  }
  return 0;
}

