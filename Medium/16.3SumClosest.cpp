/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int first = 0, second = 1, third = nums.size() - 1;
        int closestSum = nums[first] + nums[second] + nums[third];
        while (first < second && second < third) {
            if (first + 1 == second && second + 1 == third) {
                break;
            }
            int tmp = 0;
            if (closestSum == target) {
                return closestSum;
            }
            else if (closestSum > target) {
                if (third - 1 != second) {
                    tmp = closestSum - nums[third--] + nums[third];
                } else {
                    break;
                }

            }
            else {
                if (second + 1 != third) {
                    tmp = closestSum - nums[second++] + nums[second];
                    if (tmp < target) {
                        for (int i = first + 1; i < second; i++) {
                            int tmp1 = tmp - nums[first] + nums[i];
                            if (tmp1 >= target) break;
                            tmp = tmp1;
                            first = i;
                        }
                    }
                    else if (tmp == target) return tmp;
                    else {
                        for (int j = first - 1; j >= 0; j--) {
                            int tmp2 = tmp - nums[first] + nums[j];
                            tmp = tmp2;
                            first = j;
                            if (tmp2 < target) break;
                        }
                    }
                } else if (first + 1 != second) {
                    tmp = closestSum - nums[first++] + nums[first];
                }

            }
            if (abs(tmp - target) < abs(closestSum - target)) {
                closestSum = tmp;
            }
        }
        return closestSum;
    }
};
int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 4, 8, 16, 32, 64, 128};
    vector<int> nums(array, array + 8);
    Solution s;
    cout << s.threeSumClosest(nums, 82) << endl;
    return 0;
}