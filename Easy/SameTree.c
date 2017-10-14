/*Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.*/

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

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p!=NULL&&q!=NULL) return (p->val==q->val)&&(isSameTree(p->left,q->left))&&(isSameTree(p->right,q->right));
    else if(p==NULL&&q==NULL) return true;
    else return false;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}