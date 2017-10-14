/*Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 
4
 to 
1
 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
bool checkPossibility(int* nums, int numsSize) {
    int count=0;
    if(numsSize==1 || numsSize==2) return true;
    for(int i=1;i<numsSize-1;i++){
    	if(!(nums[i]>=nums[i-1] && nums[i+1]>=nums[i])){
    		if(nums[i+1]>=nums[i-1]){
    			count++;
    			nums[i]=nums[i-1];
    		}else{
    			if(nums[i]<nums[i-1] && nums[i+1]<nums[i]) return false;
    			else if(nums[i]<=nums[i+1]){
    				nums[i-1]=nums[i];
    				if(i-1==0 || nums[i-2]<=nums[i-1]) count++;
    				else return false;
    			}
    			else{
    				nums[i+1]=nums[i];
    				count++;
    			}
    		}
    	}
    	if(count>1) return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
	int nums[]={1,2,3,20,2};
	printf("%d\n", checkPossibility(nums,5));
	return 0;
}