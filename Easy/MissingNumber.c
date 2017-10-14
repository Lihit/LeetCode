/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 

int missingNumber1(int* nums, int numsSize) {
    int *tmp=calloc(numsSize+1,sizeof(int));
    memset(tmp,0,(numsSize+1)*sizeof(int));
    int ret=0;
    for(int i=0;i<numsSize;i++){
    	tmp[nums[i]]++;
    }
    for(int i=0;i<numsSize+1;i++){
    	if(tmp[i]==0){
    		ret=i;
    		break;
    	}
    }
    return ret;
}

int missingNumber(int* nums, int numsSize) {
    long int sum = numsSize*(numsSize+1)/2;
    
    int i = 0;
    while(i<numsSize)
    {
        sum = sum - nums[i++];
    }
    return sum;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}