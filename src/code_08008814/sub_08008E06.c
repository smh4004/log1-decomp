/* sub_08008E06  (original: 0x08008E06-0x08008E3A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: mem@02000000.
 */
#include "ghidra_types.h"
extern int sub_08008DBE();


void sub_08008E06(int param_1,char *param_2)

{
  int iVar1;
  
  for (; *param_2 != '\0'; param_2 = param_2 + 1) {
    if (*param_2 == '\n') {
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
      *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
      iVar1 = *(int *)(param_1 + 0x18) + -1;
      *(int *)(param_1 + 0x18) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x20) = 1;
      }
    }
    else {
      sub_08008DBE(param_1);
    }
  }
  return;
}

