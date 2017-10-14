/*Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/

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

int arrayPairSum(int* nums, int numsSize) {
	int ret=0;
	int i=0;
	int j=0;
	if(nums==NULL || numsSize<1){
		ret=-1;
		return ret;
	}
/*	for(i=0;i<numsSize-1;i++){
		for(j=i+1;j<numsSize;j++){
			if(*(nums+i) > *(nums+j)){
				int tmp=*(nums+i);
				*(nums+i)=*(nums+j);
				*(nums+j)=tmp;
			}
		}
	}*/
	quick_sort(nums,0,numsSize-1);
	for(i=0;i<numsSize/2;i++){
		ret+=*(nums+2*i);
	}
	return ret;
}
int main(){
	int a[]={1,4,3,2};
	int ret=arrayPairSum(a,4);
	printf("%d\n", ret);
	return 0;
}
