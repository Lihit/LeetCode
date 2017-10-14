/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if ((nums1Size + nums2Size) % 2) {
		int median = (nums1Size + nums2Size) / 2;
		int ret = 0;
		int i = 0, j = 0, k = 0, flag3 = 0, flag4 = 0;
		for (k = 0;k<median+1;k++) {
			if (nums1[i] <= nums2[j] && flag3 == 0 || flag4 == 1) {
				ret = nums1[i];
				i++;
			}
			else if (nums1[i]>nums2[j] && flag4 == 0 || flag3 == 1) {
				ret = nums2[j];
				j++;
			}
			if (i>nums1Size - 1) { i = nums1Size - 1; flag3 = 1; }
			if (j>nums2Size - 1) { j = nums2Size - 1;flag4 = 1; }
		}
		return ret;
	}
	else {
		int median = (nums1Size + nums2Size) / 2;
		int i = 0, j = 0, k = 0,flag3 = 0, flag4 = 0;
		int ret1 = 0, ret2 = 0;
		for (k = 0;k<median+1;k++) {
			if (nums1[i]<=nums2[j] && flag3 == 0 || flag4 == 1) {
				ret1 = nums1[i];
				i++;
			}
			else if (nums1[i]>nums2[j] && flag4 == 0 || flag3 == 1) {
				ret1 = nums2[j];
				j++;
			}
			if (i>nums1Size - 1) { i = nums1Size - 1; flag3 = 1; }
			if (j>nums2Size - 1) { j = nums2Size - 1; flag4 = 1; }
			if (k == median-1) ret2 = ret1;
		}
		return (ret1 + ret2) / 2.0;
	}
}
int main(int argc, char const *argv[])
{
	int nums1[] = { 1,2 ,2};
	int nums2[] = { 3,4};
	printf("%f\n", findMedianSortedArrays(nums1, 3, nums2, 2));
	return 0;
}