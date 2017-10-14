/*Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isInArray(int *nums,int numsSize,int num){
	if(nums==NULL) return false;
	for(int i=0;i<numsSize;i++){
		if(nums[i]==num) return true;
	}

}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {\
	if(nums2Size==0 || nums1Size==0) return NULL;
	int *ReturnArray=NULL;
	int count=0;
    if(nums1Size<=nums2Size){
    	for(int i=0;i<nums1Size;i++){
    		if(isInArray(nums2,nums2Size,nums1[i]) && !isInArray(ReturnArray,count,nums1[i])){
    			ReturnArray=realloc(ReturnArray,sizeof(int)*(count+1));
    			ReturnArray[count]=nums1[i];
    			count++;
    		}
    	}
    	* returnSize=count;
    	return ReturnArray;
    }else {
    	return intersection(nums2,nums2Size,nums1,nums1Size,returnSize);
    }
}

int main(int argc, char const *argv[])
{
	
	return 0;
}