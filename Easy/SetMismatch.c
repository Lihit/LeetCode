/*The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int *ret=calloc(2,sizeof(int));
    int sum=0;
    int tmp[10000]={0};
    for(int i=0;i<numsSize;i++){
    	sum+=nums[i];
    	tmp[nums[i]-1]++;
    	if(tmp[nums[i]-1]==2){
    		ret[0]=nums[i];
    	}
    }
    ret[1]=numsSize*(numsSize+1)/2-sum-ret[0];
    * returnSize=2;
    return ret;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}