/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
void moveZeroes(int* nums, int numsSize) {
    int i=0,count=0;
    for(i=0;i<numsSize;i++){
    	if(nums[i]!=0){
    		nums[count]=nums[i];
    		count++;
    	}
    }
    for(i=count;i<numsSize;i++){
    	nums[i]=0;
    }
}
int main(int argc, char const *argv[])
{
	int i=0;
	int nums[]={0};
	moveZeroes(nums,1);
	for(i=0;i<1;i++){
		printf("%d\n",nums[i] );
	}
	return 0;
}