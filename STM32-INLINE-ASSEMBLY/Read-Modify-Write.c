#include <stdio.h>
int main(){
	int num = 1;
	__asm volatile(
	"ADD %0,%0,#65"
	:"+r" (num)//%0 = %0 + 65

	           //The same register value is modified and stored back into num.
	:
	:"cc"
	);
	 printf("num = %d", num);
}
