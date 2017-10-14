/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int maxSubArray(int* nums, int numsSize) {
    int curSum = nums[0],maxSum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (curSum <= 0) curSum = nums[i];
        else curSum += nums[i];
        if (curSum > maxSum) maxSum = curSum;
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
	
	return 0;
} 
