/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums2.push_back(2);
    nums1.push_back(10);
    nums2.push_back(4);
    nums2.push_back(6);
    nums2.push_back(7);
    nums1.resize(10);
    Solution s;
    s.merge(nums1, 2, nums2, 4);
    for (int i = 0; i < 10; i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}