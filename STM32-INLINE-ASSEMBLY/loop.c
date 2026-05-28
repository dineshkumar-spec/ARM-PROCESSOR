//Write an inline assembly loop to sum numbers from 1 to N.
#include <stdio.h>
int main(){
	int count = 1;
	int sum=0;
	int n = 5;
    __asm volatile(
    "loop:\n"
    "ADD %1,%1,%0\n"//sum = sum + count
    "ADD %0,%0, #1\n"	//count++
    "CMP %0,%2\n"   //compare with 5
    "BLE loop\n"      //if count<5 go to loop
    :"+r" (count), "+r" (sum)
    :"r" (n)
	:"cc"
    );
    printf("Count = %d\n",count);
	return 0;
}
