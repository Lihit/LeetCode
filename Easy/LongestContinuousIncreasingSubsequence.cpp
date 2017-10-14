/*Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int findLengthOfLCIS(int* nums, int numsSize) {
	if(numsSize==0) return 0;
    int maxnum=1;
    int tmp=1;
    for(int i=1;i<numsSize;i++){
    	if(nums[i]>nums[i-1]) tmp++;
    	else tmp=1;
    	maxnum=maxnum>tmp?maxnum:tmp;
    }
    return maxnum;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}