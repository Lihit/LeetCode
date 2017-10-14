/*Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry=1;
    * returnSize=digitsSize;
    for(int i=digitsSize-1;i>=0;i--){
    	digits[i]=digits[i]+carry;
    	if(digits[i]>=10){
    		digits[i]-=10;
    		carry=1;
    	}
    	else{
    		return digits;
    	}
    }
    if(carry){
    	digits=(int*)realloc(digits,(digitsSize+1)*sizeof(int));
    	memmove(digits+1,digits,digitsSize*sizeof(int));
    	digits[0]=carry;
    	* returnSize+=1;
    }
    return digits;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}