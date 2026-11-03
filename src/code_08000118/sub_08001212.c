/* sub_08001212  (original: 0x08001212-0x0800124C in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 43% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005F2C();
extern int sub_080097C8();
extern int sub_080026F8();
extern int sub_080022BA();
extern int sub_0800AD54();
extern int sub_0800ACFE();
extern ushort volatile DAT_03003d14;
extern int volatile DAT_030007d0;
extern undefined volatile DAT_03000110;
extern undefined volatile DAT_03000190;
extern undefined4 volatile DAT_03000590;


undefined4 sub_08001212(void)

{
  sub_080022BA();
  sub_080026F8();
  if (((int)((uint)DAT_03003d14 << 0x1c) < 0) && (DAT_030007d0 != 0)) {
    sub_08005F2C(&DAT_03000110);
    sub_0800AD54(&DAT_03000190);
    sub_0800ACFE(0);
    sub_080097C8(&DAT_03000590);
  }
  return 0;
}

