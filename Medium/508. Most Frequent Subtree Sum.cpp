//
// Created by wenshao on 2017/12/3.
//

/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

5
/  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

5
/  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int helper(TreeNode *root, unordered_map<int, int> &mymap, int &maxcount) {
        if (root == NULL) return 0;
        int leftsum = helper(root->left, mymap, maxcount);
        int rightsum = helper(root->right, mymap, maxcount);
        mymap[root->val + leftsum + rightsum] += 1;
        if (mymap[root->val + leftsum + rightsum] > maxcount) maxcount = mymap[root->val + leftsum + rightsum];
        return root->val + leftsum + rightsum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> mymap;
        int maxcount = 0;
        int sum = helper(root, mymap, maxcount);
        vector<int> ret;
        for (auto p:mymap) {
            if (p.second == maxcount) ret.push_back(p.first);
        }
        return ret;
    }
};

int main() {
    return 0;
}