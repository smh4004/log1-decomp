/* sub_0800162A  (original: 0x0800162A-0x08001690 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 55% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_08000A58();
extern int sub_08008E06();
extern int sub_08009486();
extern int volatile DAT_030046b8;
extern ushort volatile DAT_02029d9e;
extern short volatile DAT_02029da0;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0800ff6c;


void sub_0800162A(int param_1)

{
  int iVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486((int *)&DAT_0800ff6c,&DAT_02029d94);
  if (DAT_030046b8 == 0) {
    DAT_02029d9e = 8;
    DAT_02029da0 = 10;
    sub_08008E06(&DAT_02029d94,(byte *)"None Completed");
  }
  else {
    iVar1 = 0;
    do {
      if (DAT_030046b8 <= (int)((uint)*(byte *)(param_1 + 4) + iVar1)) break;
      DAT_02029d9e = 6;
      DAT_02029da0 = (short)iVar1 + 6;
      sub_08008E06(&DAT_02029d94,*(byte **)(((uint)*(byte *)(param_1 + 4) + iVar1) * 4 + 0x30046bc))
      ;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 9);
  }
  sub_08008D8A(0x2029d94);
  return;
}

