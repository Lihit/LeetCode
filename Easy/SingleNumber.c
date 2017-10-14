/*Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while( low<high && arr[low]<=key )
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;

    return low;
}

void quick_sort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }

    return;
}

int singleNumber(int* nums, int numsSize) {
    quick_sort(nums,0,numsSize-1);
    int i=0;
    if(numsSize==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[numsSize-1]!=nums[numsSize-2]) return nums[numsSize-1];
    for(i=0;i<numsSize-1;i=i+2){
    	if(nums[i]!=nums[i+1]) return nums[i];
    }
}

//新的解法
int singleNumber_new(int* nums, int numsSize) {
    int result=0;
    int i=0;
    for(i = 0; i < numsSize; i++)
        result ^= nums[i];
    return result;
}

int main(int argc, char const *argv[])
{
	int nums[]={1};
	printf("%d\n", singleNumber_new(nums,1));
	return 0;
}