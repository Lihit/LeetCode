/*Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getMaxNumIndex(int* nums, int numsSize){
	int ret=nums[0];
	int ret_index=0;
	for(int i=1;i<numsSize;i++){
		if(nums[i]>ret){
			ret=nums[i];
			ret_index=i;
		}
	}
	return ret_index;
}
char** findRelativeRanks(int* nums, int numsSize, int* returnSize) {
	int count=0;
	char ** ret=(char **)malloc(sizeof(char *)*numsSize);
	char names[][20]={"Bronze Medal", "Silver Medal", "Gold Medal"};
    for(int i=0;i<numsSize;i++){
    	nums[getMaxNumIndex(nums,numsSize)]=--count;
    }
    for(int i=0;i<numsSize;i++){
    	ret[i]=(char *)malloc(sizeof(char)*20);
    	if(nums[i]>-4){
    		strcpy(ret[i],names[nums[i]+3]);
    	}else{
    		sprintf(ret[i],"%d",abs(nums[i]));
    	}
    }
    * returnSize=numsSize;
    return ret;
}
int main(int argc, char const *argv[])
{
	int nums[]={100,211,13,4,5};
	int numSize=0;
	char **ret=findRelativeRanks(nums,5,&numSize);
	for(int i=0;i<numSize;i++){
		printf("%s\n", ret[i]);
	}
	return 0;
}