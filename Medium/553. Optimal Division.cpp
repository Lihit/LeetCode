//
// Created by wenshao on 18-3-20.
//

/*
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant,
since they don't influence the operation priority. So you should return "1000/(100/10/2)".

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        if(!nums.size()) return ans;
        ans = to_string(nums[0]);
        if(nums.size()==1) return ans;
        if(nums.size()==2) return ans + "/" + to_string(nums[1]);
        ans += "/(" + to_string(nums[1]);
        for(int i = 2; i < nums.size();++i)
            ans += "/" + to_string(nums[i]);
        ans += ")";
        return ans;
    }
};

int main() {
    vector<int> nums={10000,1000,100,10,2};
    Solution s;
    string ret = s.optimalDivision(nums);
    cout<<ret<<endl;
    return 0;
}