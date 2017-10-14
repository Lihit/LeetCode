/*Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
double findMaxAverage1(int* nums, int numsSize, int k) {
    double ret=0;
    for(int i=0;i<=numsSize-k;i++){
    	double sum=0;
    	for(int j=0;j<k;j++){
    		sum+=nums[i+j];
    	}
    	if(sum>ret) ret=sum;
    }
    return ret/k;
}

double findMaxAverage(int* nums, int numsSize, int k) {
    double MaxSum=0;
    for(int i=0;i<k;i++){
    	MaxSum+=nums[i];
    }
    if(numsSize==k) return MaxSum/k;
    double tmp=MaxSum;
    for(int i=1;i<=numsSize-k;i++){
    	tmp-=nums[i-1];
    	tmp+=nums[i+k-1];
    	if(tmp>MaxSum) MaxSum=tmp;
    }
    return MaxSum/k;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}