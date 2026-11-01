/* sub_0800B110  (original: 0x0800B110-0x0800B18E in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int sub_08003398();
extern int sub_08005526();
extern undefined1 volatile DAT_0300004e;


undefined4 sub_0800B110(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  short local_18;
  short sStack_16;
  
  if ((param_2 == 0) &&
     (iVar2 = *(int *)(param_1 + 0x3c), (&DAT_0300004e)[*(byte *)(iVar2 + 6)] != '\0')) {
    uVar1 = sub_08003398();
    local_18 = (short)uVar1;
    if ((*(short *)(iVar2 + 8) <= local_18) &&
       (((local_18 < *(short *)(iVar2 + 0xc) &&
         (sStack_16 = (short)((uint)uVar1 >> 0x10), *(short *)(iVar2 + 10) <= sStack_16)) &&
        (sStack_16 < *(short *)(iVar2 + 0xe))))) {
      *(undefined4 *)(param_1 + 0x38) = 0x8002553;
      (&DAT_0300004e)[*(byte *)(iVar2 + 6)] = (&DAT_0300004e)[*(byte *)(iVar2 + 6)] + -1;
      sub_0800ACFE(7);
      sub_08005526(*(undefined1 *)(iVar2 + 4));
      return 1;
    }
  }
  return 0;
}

