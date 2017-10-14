/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/

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

int getSum(int **nums, int *numSize){
	if (nums == NULL || numSize == NULL) return 0;
	int i=0,ret=0;
	for(i=0;i<*numSize;i++){
		ret+=*((int *)*nums + i);
	}
	return ret;
}
void getTreeNums(struct TreeNode* root, int *sum) {
	if (root == NULL) return;
	getTreeNums(root->right, sum);
	*sum+=root->val;
	root->val=*sum;
	getTreeNums(root->left, sum);
}
void ReplaceVal(struct TreeNode* root, int old, int new) {
	if (root == NULL) return;
	if (root->val == old) {
		root->val = new;
		return;
	}
	ReplaceVal(root->left, old, new);
	ReplaceVal(root->right, old, new);
}
struct TreeNode* CumSum(struct TreeNode* root, int **nums, int *numSize) {
	if (nums == NULL || numSize == NULL) return NULL;
	int i = 0, j = 0;
	for (i = 0;i<*numSize;i++) {
		int tmp = *((int *)*nums + i);
		for (j = i + 1;j<*numSize;j++) {
			*((int *)*nums + i) += *((int *)*nums + j);
		}
		ReplaceVal(root, tmp, *((int *)*nums + i));
	}
	return root;
}

struct TreeNode* convertBST(struct TreeNode* root) {
	if (root == NULL) return NULL;
	int sum = 0;
	getTreeNums(root, &sum);
	return root;
}

void printTree(struct TreeNode* root) {
	if (root == NULL) return;
	printf("%d\n", root->val);
	printTree(root->left);
	printTree(root->right);
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

/*	int numSize = 0;
	int *nums = calloc(1, sizeof(int));
	getTreeNums(&t1, &nums, &numSize);
	for (int i = 0;i<numSize;i++) {
		printf("%d\n", *(nums + i));
	}*/
	struct TreeNode* root = convertBST(&t1);
	printTree(root);
	return 0;
}