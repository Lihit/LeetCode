/*You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
 Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
 If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
1 All elements in nums1 and nums2 are unique.
2 The length of both nums1 and nums2 would not exceed 1000.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {

	int *numsReturn=NULL;
	int i=0;
	int j=0;
	int k=0;
	numsReturn=(int *)malloc(findNumsSize*sizeof(int));
	for(i=0;i<findNumsSize;i++){
		int flag=0;
		for(j=0;j<numsSize;j++){
			if(findNums[i]==nums[j]){
				for(k=j+1;k<numsSize;k++){
					if(nums[k]>findNums[i]){
						numsReturn[i]=nums[k];
						flag=1;
						break;
					}
				}
				if(flag==0){
					numsReturn[i]=-1;
				}
			}
		if(flag==1) break;
		}


	}

	* returnSize=findNumsSize;
    return numsReturn;
}

int main(int argc, char const *argv[])
{
	int findNums[]={4,1,2};
	int nums[]={1,3,4,2};
	int returnSize=0;
	int *numsReturn=nextGreaterElement(findNums,3,nums,4,&returnSize);
	int i=0;
	for(i=0;i<returnSize;i++){
		printf("%d\n", numsReturn[i]);
	}
	return 0;
}