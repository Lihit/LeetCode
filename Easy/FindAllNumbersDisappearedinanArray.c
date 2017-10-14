/*Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int *tmp=calloc(numsSize,sizeof(int));
	memset(tmp,0,numsSize*sizeof(int));
	int i=0;
	int count=0;
	int *returnArray=NULL;
	for(i=0;i<numsSize;i++){
		tmp[nums[i]-1]+=1;
	}
	for(i=0;i<numsSize;i++){
		if(tmp[i]==0){
			count++;
			returnArray=realloc(returnArray,count*sizeof(int));
			returnArray[count-1]=i+1;
		}
	}
	*returnSize=count;
    return returnArray;

}
int main(int argc, char const *argv[])
{
	int *a=calloc(3,sizeof(int));
	a[0]=1;
	a[1]=12;
	a[2]=22;0
	a=realloc(a,sizeof(int));
	a[0]=55555;
	printf("%d\n", a[1]);
	return 0;
}