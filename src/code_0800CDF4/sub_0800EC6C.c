/* sub_0800EC6C  (original: 0x0800EC6C-0x0800EC7E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"

/* ARM semihosting SYS_WRITEC (3): write the character param_1 (passed by address in r1) to the debugger console. */
int sub_0800EC6C(int param_1)
{
  volatile unsigned char c = (unsigned char)param_1;
  register int r0 __asm__("r0") = 3;
  register volatile unsigned char *r1 __asm__("r1") = &c;
  __asm__ volatile ("swi 0xab" : "+r"(r0), "+r"(r1) : : "r2", "r3", "memory");
  return r0;
}
