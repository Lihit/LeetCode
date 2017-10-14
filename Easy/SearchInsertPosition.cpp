/*Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int searchInsert1(int* nums, int numsSize, int target) {
    for(int i=0;i<numsSize;i++){
    	if(target<=nums[i]) return i;
    }
    return numsSize;
}
int searchInsert(int* nums, int numsSize, int target) {
    if(numsSize==0) return 0;
    if(target==nums[numsSize/2]) return numsSize/2;
    else if(target<nums[numsSize/2]) return searchInsert(nums,numsSize/2,target);
    else return numsSize/2+1+searchInsert(nums+numsSize/2+1,ceil(numsSize/2.0)-1,target);
}
int main(int argc, char const *argv[])
{
	int nums[5]={1,2,3,5,6};
	printf("%d\n", searchInsert(nums,5,11));
	return 0;
}