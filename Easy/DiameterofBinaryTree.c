/*Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
int getTreeDeep(struct TreeNode* root){
	if(root==NULL) return 0;
	int leftDeep=getTreeDeep(root->left);
	int rightDeep=getTreeDeep(root->right);
	return leftDeep>rightDeep?leftDeep+1:rightDeep+1;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int leftDeep=getTreeDeep(root->left);
    int rightDeep=getTreeDeep(root->right);
    int deep1=leftDeep+rightDeep;
    int deep2=diameterOfBinaryTree(root->left);
    int deep3=diameterOfBinaryTree(root->right);
    return deep1>deep2?(deep1>deep3?deep1:deep3):(deep2>deep3?deep2:deep3);
}
int main(int argc, char const *argv[])
{
	printf("%d\n", (int)fmax(1,2));
	return 0;
}