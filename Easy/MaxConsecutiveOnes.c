/*Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int left=0,right=0,i=0,count=0,j=0;
    while(i<numsSize){
    	if(nums[i]==1){
    		left=i;
    		if(i==numsSize-1){
    			right=numsSize;
    			count=right-left>count?right-left:count;
    			i++;
    		}else{
    			for(j=i+1;j<numsSize;j++){
    				if(nums[j]==0){
    					right=j;
    					break;
    				}
    				else if(j==numsSize-1){
    					right=numsSize;
    					break;
    				}
    			}    	
    			count=right-left>count?right-left:count;
    			i=j+1;		
    		}

    	}else{
    		i++;
    	}
    }
    return count;
}

int main(int argc, char const *argv[])
{
	int a[]={0,0};
	printf("%d\n",findMaxConsecutiveOnes(a,2) );
	return 0;
}