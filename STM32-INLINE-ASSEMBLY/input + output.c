#include <stdio.h>
int main()
{
  static int val1=100, val2=100, result;
  __asm volatile(
	"ADD %0, %1, %2"
	:"=r" (result)
	:"r" (val1), "r" (val2)
  );
}
