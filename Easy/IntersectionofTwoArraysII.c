/*Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAP_SIZE 1000
struct HashMap
{
	int count;
	int count1;
	int val;
	struct HashMap *next;
} disHashMap[MAP_SIZE];


void addToHashMap(int key,int flag) {
	int slot = abs(key) % MAP_SIZE;
	struct HashMap *p;
    if(flag==1){
		if (disHashMap[slot].val == key) {
			disHashMap[slot].count++;
		} else if (disHashMap[slot].val == 0) {
			disHashMap[slot].val = key;
			disHashMap[slot].count++;
		} else {
			p = &disHashMap[slot];
			while (p->val != key && p->next != NULL) {
				p = p->next;
			}
			if (p->val == key) {
				p->count++;
			} else {
				p->next = (struct HashMap *)malloc(sizeof(struct HashMap));
				p = p->next;
				p->val = key;
				p->count = 1;
				p->next = NULL;
			}
		}
	}
	else if(flag==2){
		if (disHashMap[slot].val == key) {
			disHashMap[slot].count1++;
		} else if (disHashMap[slot].val == 0) {
			disHashMap[slot].val = key;
			disHashMap[slot].count1++;
		} else {
			p = &disHashMap[slot];
			while (p->val != key && p->next != NULL) {
				p = p->next;
			}
			if (p->val == key) {
				p->count1++;
			} else {
				p->next = (struct HashMap *)malloc(sizeof(struct HashMap));
				p = p->next;
				p->val = key;
				p->count1 = 1;
				p->next = NULL;
			}
		}
	}

}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	struct HashMap *p=NULL;
	for (int k = 0; k < MAP_SIZE; k++) {
		disHashMap[k].val = 0;
		disHashMap[k].count = 0;
		disHashMap[k].next = NULL;
	}    
	for(int i=0;i<nums1Size;i++){
		addToHashMap(nums1[i],1);
	}
	for(int j=0;j<nums2Size;j++){
		addToHashMap(nums2[j],2);
	}
	int count=0;
	int *returnArray=NULL;
	for (int k = 0; k < MAP_SIZE; k++) {
		p = &disHashMap[k];
		while (p != NULL) {
			int tmp=p->count<p->count1?p->count:p->count1;
			if (tmp>0) {
				count+=tmp;
				returnArray=realloc(returnArray,count*sizeof(int));
				for(int i=0;i<tmp;i++){
					returnArray[count-i-1]=p->val;
				}
			}
			p = p->next;
		}		
	}   
	*returnSize=count;
	return returnArray; 	
}
int main(int argc, char const *argv[])
{
	double d=2147483648;
	printf("%d\n",-2222%1000 );
	return 0;
}