/* sub_0800CF92  (original: 0x0800CF92-0x0800CFB6 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_0800494A();


undefined4 sub_0800CF92(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    sub_0800494A(0x3000818,*(int *)(param_1 + 4),0);
    iVar1 = iVar1 + 1;
  } while (iVar1 <= (int)(uint)*(ushort *)(param_1 + 8));
  return 1;
}

