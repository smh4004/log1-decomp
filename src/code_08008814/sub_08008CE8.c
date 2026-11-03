/* sub_08008CE8  (original: 0x08008CE8-0x08008D00 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08008B30();

/* sub_08008CE8(obj, fmt, ...): variadic wrapper. Spills r0-r3 (push {r0-r3}), builds a va_list pointing at the
   first unnamed argument and calls sub_08008B30(obj, fmt, &ap); returns its result. Hand-written because Ghidra
   copies only the named registers and loses the stack arguments. */
int sub_08008CE8(int obj, int fmt, ...)
{
  __builtin_va_list ap;
  int r;
  __builtin_va_start(ap, fmt);
  r = sub_08008B30(obj, fmt, &ap);
  __builtin_va_end(ap);
  return r;
}
