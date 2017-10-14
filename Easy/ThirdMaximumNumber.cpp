/*Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        int count = 1, ret = q.top(), maxnum = ret;
        if (nums.size() < 3) return ret;
        q.pop();
        while (!q.empty()) {
            if (q.top() != ret) {
                ret = q.top();
                count++;
            }
            if (count == 3) return ret;
            q.pop();
        }
        return maxnum;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums;
    nums.push_back(2);
    //nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    Solution s;
    int ret = s.thirdMax(nums);
    cout << ret << endl;
    return 0;
}