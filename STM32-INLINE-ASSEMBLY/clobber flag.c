//Use CMP instruction and include "cc".
#include <stdio.h>
int main(){
	int val1 = 100;
	int val2 = 20;
	__asm volatile(
	"CMP %0, %1"
	:
	:"r" (val1),
	 "r" (val2)
	:"cc"
	);
	printf("val1 = %d\n",val1);
	printf("val2 = %d\n",val2);
	return 0;
}
