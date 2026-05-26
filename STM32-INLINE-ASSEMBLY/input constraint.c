
#include <stdio.h>
int main(){
	int value = 78;
	asm volatile(
	"MOV R0, %0"
	:
	:"r" (value)
	:"r0"
	);
}
