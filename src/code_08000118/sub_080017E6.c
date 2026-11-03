/* sub_080017E6  (original: 0x080017E6-0x08001874 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 95% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000A32();
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_08008E3A();
extern int sub_08000A58();
extern int sub_08008E06();
extern int sub_08009486();
extern ushort volatile DAT_02029d9e;
extern short volatile DAT_02029da0;
extern undefined1 volatile DAT_02029d94;
extern undefined4 volatile DAT_0202c224;
extern undefined4 volatile DAT_0202c228;
extern undefined volatile DAT_0800ffa0;
extern undefined volatile gUnknown_081C6224;


void sub_080017E6(int param_1)

{
  int iVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486((int *)&DAT_0800ffa0,&DAT_02029d94);
  if (*(char *)(param_1 + 6) == '\0') {
    DAT_02029d9e = 0xc;
    DAT_02029da0 = 10;
    sub_08008E06(&DAT_02029d94,(byte *)"Empty");
  }
  else {
    iVar1 = 0;
    if (*(char *)(param_1 + 6) != '\0') {
      do {
        DAT_02029d9e = 5;
        DAT_02029da0 = (short)iVar1 + 6;
        sub_08008E3A(&DAT_02029d94,"%d %s",(&DAT_0202c224)[iVar1 * 2],
                     *(undefined4 *)
                      (&gUnknown_081C6224 +
                      (uint)((&DAT_0202c224)[iVar1 * 2] != 1) * 4 + (&DAT_0202c228)[iVar1 * 2] * 8))
        ;
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)*(byte *)(param_1 + 6));
    }
  }
  if (*(byte *)(param_1 + 4) == 0) {
    sub_08000A32(2,0x10);
  }
  else {
    sub_08000A32(3,*(byte *)(param_1 + 4) + 5);
  }
  sub_08008D8A(0x2029d94);
  return;
}

