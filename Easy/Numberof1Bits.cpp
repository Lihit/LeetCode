/*Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef unsigned int uint32_t;
int hammingWeight(uint32_t n) {
	int ret=0;
	while(n){
		if(n%2==1) ret++;
		n/=2;
	}
    return ret;
}
int main(int argc, char const *argv[])
{
	printf("%d\n",hammingWeight(11) );
	return 0;
}