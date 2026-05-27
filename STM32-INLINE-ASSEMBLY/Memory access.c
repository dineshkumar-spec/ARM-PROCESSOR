//MEMORY ACCESS
#include <stdio.h>
int main(){
	int source = 200;
	int destination = 0;
	int temp;
	__asm volatile(
	"LDR %0, [%1]\n"
	"STR %0, [%2]\n"
	:"=r" (temp)
	:"r" (&source), "r" (&destination)
	:"memory"
	);
	printf("Source = %d\n",source);
	printf("Destination = %d\n",destination);
	return 0;
}
