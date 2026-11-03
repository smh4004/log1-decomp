/* sub_0800C090  (original: 0x0800C090-0x0800C0EA in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800946E();
extern int sub_0800084A();
extern int sub_08008D14();
extern int sub_08008D8A();
extern int sub_08000A58();
extern int sub_08009486();
extern byte volatile DAT_02029d94;
extern undefined volatile gUnknown_08012098;
extern undefined volatile DAT_08012084;
extern undefined volatile DAT_080120b8;
extern undefined volatile gUnknown_080120A8;


void sub_0800C090(void)

{
  int iVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_0800946E(&DAT_08012084,&DAT_02029d94);
  sub_08009486((int *)&DAT_080120b8,&DAT_02029d94);
  DAT_02029d94 = 0xe;
  iVar1 = sub_0800084A(0);
  if (iVar1 == 0) {
    sub_0800946E(&gUnknown_08012098,&DAT_02029d94);
  }
  iVar1 = sub_0800084A(1);
  if (iVar1 == 0) {
    sub_0800946E(&gUnknown_080120A8,&DAT_02029d94);
  }
  DAT_02029d94 = 0xf;
  sub_08008D8A(0x2029d94);
  return;
}

