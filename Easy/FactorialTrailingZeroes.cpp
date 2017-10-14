/*Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

double helper(int n){
	double ret=1;
	for(int i=1;i<=n;i++){
		ret*=i;
	}
	return ret;
}
int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}
int main(int argc, char const *argv[])
{
	printf("%d\n",trailingZeroes(20));
	return 0;
}