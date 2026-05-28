#include <stdio.h>
int main(){
	int value = 5;
	__asm volatile(
	"MRS %0,CONTROL"
	:"+r" (value)
	:
	:"memory"
	);
	printf("Value = %d\n",value);
	return 0;
}
