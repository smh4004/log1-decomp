/* sub_08005A94  (original: 0x08005A94-0x08005AE4 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002486();
extern int sub_0800507A();
extern int sub_08002716();
extern int sub_0800236E();
extern undefined4 volatile DAT_03000600;
extern undefined * volatile gUnknown_08011494;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;


void sub_08005A94(int param_1)

{
  int iVar1;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_18 ((undefined1 *)((char *)__frame + 0x0))
  iVar1 = sub_08002716();
  *(undefined2 *)(iVar1 + 0x20) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_1 + 0xc);
  *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 6);
  sub_08002486(iVar1,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)]],
               &gUnknown_08011494,0);
  *(undefined4 *)(iVar1 + 0x38) = 0x800599b;
  *(int *)(iVar1 + 0x3c) = param_1;
  sub_0800236E(auStack_18,iVar1);
  sub_0800507A(DAT_03000600,auStack_18,0,0);
  return;
}

