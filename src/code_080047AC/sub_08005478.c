/* sub_08005478  (original: 0x08005478-0x080054AE in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: cand-error, equal.
 */
#include "ghidra_types.h"
extern int __call_via_r3();
extern int volatile DAT_0300087c;


undefined4 sub_08005478(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_0300087c) {
    do {
      iVar1 = __call_via_r3();
      if (iVar1 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0300087c);
  }
  return 0;
}

