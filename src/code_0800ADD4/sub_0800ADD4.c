/* sub_0800ADD4  (original: 0x0800ADD4-0x0800AE10 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005EA6();
extern undefined volatile DAT_085c2250;
extern undefined volatile DAT_085c2251;
extern undefined volatile gUnknown_085C224C;
extern undefined volatile DAT_085c2254;


void sub_0800ADD4(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = (uint)*(byte *)(param_1 + 0x14) * 0x18;
  *(undefined1 *)(param_1 + 0xc) = 0x38;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(&gUnknown_085C224C + iVar2);
  *(char *)(param_1 + 0x11) =
       (char)((int)((uint)*(ushort *)(param_1 + 6) * (uint)*(ushort *)(param_1 + 4)) >> 6);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(&DAT_085c2254 + iVar2) + 4);
  *(undefined *)(param_1 + 0xe) = (&DAT_085c2250)[iVar2];
  *(undefined *)(param_1 + 0xf) = (&DAT_085c2251)[iVar2];
  uVar1 = sub_08005EA6(**(int **)(&DAT_085c2254 + iVar2));
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  return;
}

