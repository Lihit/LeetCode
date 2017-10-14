/*Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
int removeElement(int* nums, int numsSize, int val) {
    int i=0;
    while(i<numsSize){
    	if(nums[i]==val){
    		if(i==numsSize-1) numsSize--;
    		else{
    			memmove(nums+i,nums+i+1,(numsSize-i-1)*sizeof(int));
    			numsSize--;
    		}
    	}
    	else i++;
    }
    return numsSize;
}
int main(int argc, char const *argv[])
{
	int nums[5]={1,2,3,4,5};
    int numsSize=removeElement(nums,5,2);
    for(int i=0;i<numsSize;i++){
        printf("%d\n",nums[i]);
    }
	
	return 0;
}