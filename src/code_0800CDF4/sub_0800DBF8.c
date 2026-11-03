/* sub_0800DBF8  (original: 0x0800DBF8-0x0800DC0C in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800AB1A();
extern ushort volatile REG_IME;

/* Soft reset: sub_0800AB1A, interrupts off (REG_IME = 0), then BIOS SoftReset (swi 0). */
void sub_0800DBF8(void)
{
  sub_0800AB1A();
  REG_IME = 0;
  __asm__ volatile ("swi 0" : : : "r0", "r1", "r2", "r3", "memory");
}
