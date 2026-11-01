/* sub_080048FA  (original: 0x080048FA-0x0800494A in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 61% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009744();
extern int sub_080098F8();
extern int sub_0800ACFE();
extern int sub_0800A6B2();
extern undefined4 volatile DAT_03000c18;
extern ushort volatile DAT_03003d14;
extern ushort volatile DAT_03000832;
extern ushort volatile DAT_03000830;


undefined4 sub_080048FA(int param_1)

{
  int iVar1;
  
  iVar1 = sub_0800A6B2(6,0x8011462);
  if (iVar1 == 0) {
    if (((DAT_03003d14 & 1) != 0) ||
       ((*(int *)(param_1 + 4) == 0 && (DAT_03000830 <= DAT_03000832)))) {
      if (*(int *)(param_1 + 4) == 0) {
        return 1;
      }
      sub_080098F8();
      sub_08009744(*(undefined4 *)(param_1 + 4));
    }
  }
  else {
    sub_0800ACFE(7);
    DAT_03000c18 = 1;
  }
  return 0;
}

