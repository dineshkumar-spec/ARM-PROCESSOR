//Store a constant value into a C variable using inline assembly.
#include <stdio.h>
int main(){
    const int value = 45;
	int result;
	asm volatile(
	"MOV %0, %1"
	:"=r" (result)
	:"r" (value)
	);
	printf("Result=%d\n",result);
	return 0;
}
