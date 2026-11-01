/* sub_0800357C  (original: 0x0800357C-0x080035B0 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int volatile DAT_030007e8;


bool sub_0800357C(undefined4 *param_1)

{
  short *psVar1;
  bool bVar2;
  undefined4 uStack_8;
  
  bVar2 = DAT_030007e8 != 0;
  if (bVar2) {
    psVar1 = *(short **)(param_1[2] + (uint)*(byte *)((int)param_1 + 0x13) * 4);
    uStack_8 = CONCAT22(psVar1[1] + 0x88,*psVar1 + 0xd0);
    *param_1 = uStack_8;
  }
  return bVar2;
}

