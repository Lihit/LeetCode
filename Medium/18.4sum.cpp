/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ret;
        if (n < 3) return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[n - 1] + nums[n - 2] + nums[j] < target) continue;
                if (nums[i] + nums[j + 1] + nums[j + 2] + nums[j] > target) break;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] + nums[j] < target) left++;
                    else if (nums[i] + nums[left] + nums[right] + nums[j] > target) right--;
                    else {
                        ret.push_back(vector<int> {nums[i] , nums[left] , nums[right] , nums[j]});
                        do {left++;} while (nums[left] == nums[left + 1] && left < right);
                        do {right--;} while (nums[right] == nums[right - 1] && left < right);

                    }
                }
            }
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}