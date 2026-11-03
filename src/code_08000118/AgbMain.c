/* AgbMain  (original: 0x08000274-0x080002C0 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_0800A9CC();
extern int sub_0800A9A2();
extern int sub_080096CC();
extern int sub_08009744();
extern int sub_080007D2();
extern int sub_08009766();
extern int sub_08000732();
extern byte volatile DAT_03000021;
extern byte volatile DAT_03000022;
extern undefined4 * volatile DAT_0300000b;
extern undefined volatile DAT_03000020;
extern undefined4 volatile DAT_030005e8;
extern undefined4 volatile DAT_0300463c;


void AgbMain(void)

{
  unsigned int __frame[3];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_c ((undefined1 *)((char *)__frame + 0x0))
  sub_080096CC((int)auStack_c);
  sub_08000732(&DAT_03000020);
  sub_080007D2(0x3000028);
  sub_0800A9CC(DAT_03000021);
  sub_0800A9A2(DAT_03000022);
  DAT_0300000b = &DAT_030005e8;
  sub_08009744(&DAT_0300463c);
  sub_08009766();
  return;
}

