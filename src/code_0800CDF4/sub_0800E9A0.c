/* sub_0800E9A0  (original: 0x0800E9A0-0x0800E9B0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"

/* ARM semihosting exit (ADS library _sys_exit): SYS_EXIT (0x18) with ADP_Stopped_ApplicationExit (0x20026), then
   hang. On a GBA the swi 0xAB lands in the BIOS; the loop is what actually happens. */
void sub_0800E9A0(void)
{
  register int r0 __asm__("r0") = 0x18;
  register int r1 __asm__("r1") = 0x20026;
  __asm__ volatile ("swi 0xab" : "+r"(r0), "+r"(r1) : : "r2", "r3", "memory");
  for (;;) { }
}
