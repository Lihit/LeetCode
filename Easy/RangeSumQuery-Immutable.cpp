/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            Sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return Sums[j];
        else return Sums[j] - Sums[i];
    }
public:
    vector<int> Sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
int main(int argc, char const *argv[])
{

    return 0;
}