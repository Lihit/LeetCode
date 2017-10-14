/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int comp(const void *a,const void *b)
{
  return *(int *)a-*(int *)b;
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),comp);
    return nums[numsSize/2];
}
int main(int argc, char const *argv[])
{
	int nums[]={1,2,1,1,2};
	printf("%d\n", majorityElement(nums,5));
	return 0;
}