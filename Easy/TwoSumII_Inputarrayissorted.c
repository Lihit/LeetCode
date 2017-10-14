/*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *returnArray=calloc(2,sizeof(int));
    int i=0,j=numbersSize-1;
    while(i<j){
    	int twosum=numbers[i]+numbers[j];
    	if(twosum==target) break;
    	else if(twosum>target) j--;
    	else i++;   	
    }
    * returnSize=2;
    returnArray[0]=i+1;
    returnArray[1]=j+1;
    return returnArray;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}