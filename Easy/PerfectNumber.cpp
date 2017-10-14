/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

bool checkPerfectNumber(int num) {
	if(num==1) return false;
    int tmp=1;
    for(int i=2;;i++){
    	if(num%i==0){
    		if(i==num/i) tmp+=num/i;
    		else if (i<num/i) tmp+=(i+num/i);
    		else break;
    	}
    	if(i>=num) break;
    }
    return tmp==num;
}

int main(int argc, char const *argv[])
{
	if(checkPerfectNumber(28)) printf("hello...\n");
	return 0;
}