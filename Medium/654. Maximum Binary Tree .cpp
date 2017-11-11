/* Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:

Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

Note:

    The size of the given array will be in the range [1,1000].
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    TreeNode* helper(vector<int>& nums,int left,int right){
        if(left>right) return NULL;
        vector<int>:: iterator maxPtr;
        maxPtr=max_element(nums.begin()+left,nums.begin()+right);
        int maxIndex=distance(nums.begin(),maxPtr);
        TreeNode *head=new TreeNode(*maxPtr);
        head->left=helper(nums,left,maxIndex-1);
        head->right=helper(nums,maxIndex+1,right);
        return head;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
int main(int argc, char const *argv[])
{
  
  return 0;
}