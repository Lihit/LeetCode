/*Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
bool isPerfectSquare(int num) {
	int i=1;
	while(num>0){
		num-=i;
		i+=2;
	}
	return num==0;
}
int main(int argc, char const *argv[])
{
	printf("%d\n", isPerfectSquare(225));
	return 0;
}