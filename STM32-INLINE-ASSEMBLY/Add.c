#include <stdio.h>
int main(){
	int val1 = 10, val2 = 20, result;
	asm volatile(
	  "ADD %[out], %[in1], %[in2]"
	  :[out] "=r" (result)
	  :[in1] "r" (val1),
	   [in2] "r" (val2)
	);
	printf("Result %d\n",result);
	while(1)
	return 0;
}
