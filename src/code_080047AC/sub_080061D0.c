/* sub_080061D0  (original: 0x080061D0-0x080061EC in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_08004E98();
extern int sub_080060A0();


undefined4 sub_080061D0(int param_1)

{
  sub_08004E98(0x3000864,*(int *)(param_1 + 0x10));
  sub_080060A0(param_1);
  return 1;
}

