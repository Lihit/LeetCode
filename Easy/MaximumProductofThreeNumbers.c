/*Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int cmp( const void *a , const void *b ) 
{ 
	return *(int *)a - *(int *)b; 
} 
int maximumProduct(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int maxret1=nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
    int maxret2=nums[numsSize-1]*nums[1]*nums[0];
	return maxret1>maxret2?maxret1:maxret2;
    
}
int main(int argc, char const *argv[])
{
	int nums[]={-1,-23,-111,1,2,3};
	printf("%d\n",maximumProduct(nums,6) );
	return 0;
}