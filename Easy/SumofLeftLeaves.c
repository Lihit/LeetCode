/*Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
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

int sumOfLeftLeaves(struct TreeNode* root) {
	if(root==NULL) return 0;
	int ret=0;
	if(root->left!=NULL && root->left->left==NULL &&root->left->right==NULL) ret=root->left->val;
	return ret+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
}
int main(int argc, char const *argv[])
{
	struct TreeNode t1, t2, t3, t4, t5;
	t1.val = 13;
	t1.left = &t2;
	t1.right = &t3;
	t2.val = 9;
	t2.left = NULL;
	t2.right = NULL;
	t3.val = 20;
	t3.left = &t4;
	t3.right = &t5;
	t4.val = 15;
	t4.left = NULL;
	t4.right = NULL;
	t5.val = 27;
	t5.left = NULL;
	t5.right = NULL;
	printf("%d\n", sumOfLeftLeaves(&t1));		
	return 0;
}