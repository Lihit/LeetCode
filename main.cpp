//
// Created by wenshao on 17-11-26.
//
/*Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:

Input:

2
/ \
  1   3

Output:
1

Example 2:

Input:

1
/ \
      2   3
/   / \
    4   5   6
/
7

Output:
7

Note: You may assume the tree (i.e., the given root node) is not NULL.*/
#include <iostream>

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode *root, int *leftbottomvalue, int deep, int *maxdeep) {
        if (root == NULL) return;
        else{
            deep++;
            if(deep>*maxdeep){
                *leftbottomvalue=root->val;
                *maxdeep=deep;
            }
        }
        helper(root->left,leftbottomvalue,deep,maxdeep);
        helper(root->right,leftbottomvalue,deep,maxdeep);
    }

    int findBottomLeftValue(TreeNode *root) {
        int leftbottomvalue=0,maxdeep=0,deep=0;
        helper(root,&leftbottomvalue,deep,&maxdeep);
        return leftbottomvalue;
    }
};

int main() {
    cout << "hello world" << endl;
    return 0;
}