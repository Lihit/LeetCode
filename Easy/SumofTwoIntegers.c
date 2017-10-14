/*Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int getSum(int a, int b) {
	int jw=a&b; 
	int jg=a^b; 
	while(jw) { 
		int t_a=jg; 
		int t_b=jw<<1; 
		jw=t_a&t_b; 
		jg=t_a^t_b; 	
	} 
	return jg; 
}


int main(int argc, char const *argv[])
{
	printf("%d\n", getSum(2,3));
	return 0;
}