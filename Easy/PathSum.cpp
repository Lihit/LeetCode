/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) {
	if (root == NULL) return false;
	if (root->left == NULL && root->right == NULL) {
		if (sum == root->val) return true;
		else return false;
	}
	else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main(int argc, char const *argv[])
{

	return 0;
}