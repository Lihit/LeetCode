/*Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input:
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input:
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/

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

void helper(struct TreeNode* root, int *saver) {
	if (root == NULL) return;
	if(saver[0]==-1) saver[0]=root->val;
	else if(saver[1]==-1 && root->val!=saver[0]) saver[1]=root->val;
	else if (root->val < saver[0]) {
		saver[1] = saver[0];
		saver[0] = root->val;
	}
	else if (root->val > saver[0] && root->val < saver[1]) {
		saver[1] = root->val;
	}
	helper(root->left, saver);
	helper(root->right, saver);
}
int findSecondMinimumValue(struct TreeNode* root) {
	int saver[2] = {-1,-1};
	helper(root, saver);
	return saver[1];
}
int main(int argc, char const *argv[])
{

	return 0;
}