/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.*/
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

int helper(struct TreeNode* root) {
    if(root==NULL) return 0;
    int leftLen=helper(root->left);
    int rightLen=helper(root->right);
    if(abs(leftLen-rightLen)>1) throw 0;
    printf("%d\n", root->val);
    return leftLen>rightLen?leftLen+1:rightLen+1;
}
bool isBalanced(struct TreeNode* root) {
	try{
		int deep=helper(root);
		return true;
	}
	catch(int e)
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	struct TreeNode t1, t2, t3, t4, t5,t6;
	t1.val = 15;
	t1.left = NULL;
	t1.right = &t3;
	t2.val = 14;
	t2.left = NULL;
	t2.right = &t6;
	t3.val = 21;
	t3.left = &t4;
	t3.right = &t5;
	t4.val = 20;
	t4.left = NULL;
	t4.right = NULL;
	t5.val = 233;
	t5.left = NULL;
	t5.right = NULL;	
	t6.val = 14;
	t6.left = NULL;
	t6.right = NULL;	
	if(isBalanced(&t1)){
		printf("hello\n");
	}
	return 0;
}