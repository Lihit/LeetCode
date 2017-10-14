/*We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}

int findLHS(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int ret=0,i=0,j=0;
    for(i=0;i<numsSize;i++){
    	int count=1;
    	int tmp=nums[i];
    	for(j=i+1;j<numsSize;j++){
    		if((nums[j]-tmp)<=1) count++;
    		else break;
    	}
    	if(count>ret && nums[j-1]-tmp==1) ret=count;
    }
    return ret;
}
int main(int argc, char const *argv[])
{
	int nums[]={1,1,1,1};
	printf("%d\n", findLHS(nums,4));
	return 0;
}