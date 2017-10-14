/*Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
bool isPowerOfThree(int n) {
	double tmp=n;
	while(tmp>=1){
		printf("%0.15f\n", round(tmp));
		if(ceil(tmp)!=tmp) return false;
		if((tmp-1)==0) return true;
		tmp/=3;
	}
	return false;	
}
int main(int argc, char const *argv[])
{
	int a=1162261467;
	printf("%d\n", isPowerOfThree(a));
	return 0;
}