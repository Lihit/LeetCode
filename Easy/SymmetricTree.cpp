/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool helper(struct TreeNode* leftNode,struct TreeNode* rightNode){
	if(leftNode==NULL&&rightNode==NULL) return true;
	else if(leftNode!=NULL&&rightNode!=NULL) return leftNode->val==rightNode->val&&helper(leftNode->left,rightNode->right)&&helper(leftNode->right,rightNode->left);
	else return false;
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL) return false;
    else return helper(root->left,root->right);
}
int main(int argc, char const *argv[])
{
	
	return 0;
}