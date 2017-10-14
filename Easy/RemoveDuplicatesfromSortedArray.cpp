/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int removeDuplicates(int* nums, int numsSize) {
	if(numsSize==0) return 0;
	int ret=1,i=0,j=0,flag=0;
	for(i=0;i<numsSize-1;){
		for(j=i+1;j<numsSize;j++){
			if(nums[j]!=nums[i]) break;
		}
		if(j==numsSize) break;
		nums[ret]=nums[j];
		ret++;
		i=j;
	}
    return ret;
}
int main(int argc, char const *argv[])
{
	int nums[]={1,1,2,2};
	int ret=removeDuplicates(nums,4);
	for(int i=0;i<ret;i++){
		printf("%d\n", nums[i]);
	}
	
	return 0;
}