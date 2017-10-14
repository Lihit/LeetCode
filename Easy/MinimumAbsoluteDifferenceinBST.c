/*Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.*/


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

int getMinimumDifference(struct TreeNode* root) {
    if(root==NULL) return INT_MAX;
    struct TreeNode *leftNode=root->left;
    struct TreeNode *rightNode=root->right;
    int ret1=0,ret2=0,ret3=0;
    while(leftNode){
    	if(leftNode->right) leftNode=leftNode->right;
    	else break;
    }
    while(rightNode){
    	if(rightNode->left) rightNode=rightNode->left;
    	else break;
    }
    if(leftNode==NULL && rightNode!=NULL) ret1=abs(root->val-rightNode->val);
    else if(rightNode==NULL && leftNode!=NULL) ret1=abs(root->val-leftNode->val);
    else if(rightNode!=NULL && leftNode!=NULL) ret1=abs(root->val-leftNode->val)<=abs(root->val-rightNode->val)?abs(root->val-leftNode->val):abs(root->val-rightNode->val);
    else ret1=INT_MAX;
    ret2=getMinimumDifference(root->left);
    ret3=getMinimumDifference(root->right);
    return ret1<ret2?(ret1<ret3?ret1:ret3):(ret2<ret3?ret2:ret3);
}
int main11(int argc, char const *argv[])
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
	printf("%d\n", getMinimumDifference(&t1));	
	return 0;
}

int main(int argc, char const *argv[])
{
	int ret[]={0,0};
	printf("%d\n",ret=={0,0});
	return 0;
}