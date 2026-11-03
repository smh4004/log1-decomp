/* sub_0800BEB8  (original: 0x0800BEB8-0x0800BEEC in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800242C();
extern int sub_08005EA6();
extern char volatile DAT_03004394;
extern undefined volatile gUnknown_08011F18;


void sub_0800BEB8(int param_1)

{
  if ((-1 < *(int *)(param_1 + 0x28) << 0x1b) &&
     (*(undefined4 *)(param_1 + 0x28) = 8, *(undefined **)(param_1 + 0x18) != &gUnknown_08011F18)) {
    DAT_03004394 = sub_08005EA6(0x8011ef8);
    *(char *)(param_1 + 0xd) = *(char *)(param_1 + 0xd) * '\x10' + DAT_03004394;
    sub_0800242C(param_1,0x8011f18);
  }
  return;
}

