//result = 1 if a > b else 0
#include <stdio.h>
int main(){
	int a=130,b=45,result;
	asm volatile(
	"CMP %1, %2\n"
	"BGT greater\n"
	"MOV %0, #0\n"
	"B end\n"

	"greater:\n"
	"MOV %0, #1\n"
	"end:\n"
	:"=r" (result)
	:"r" (a), "r" (b)
	:"cc"
	);
	printf("Result = %d\n",result);
	return 0;
}
