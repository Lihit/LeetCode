/*You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11*/
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
int helper(struct TreeNode* root, int target) {
	  int ret=0;
 	  if(root==NULL) return ret;
 	  if(target==root->val) {
        ret++;
    }
 	  ret+=helper(root->left,target-root->val);
 	  ret+=helper(root->right,target-root->val);
    return ret;
}
int pathSum(struct TreeNode* root, int sum) {
    if(root==NULL) return 0;
    return helper(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
}
int main(int argc, char const *argv[])
{
/*    struct TreeNode t1,t2,t3,t4,t5,t6,t7,t8,t9;
    t1.val=10;
    t1.left=&t2;  
    t1.right=&t3;
    t2.val=5;
    t2.left=&t4;
    t2.right=&t5;  
    t3.val=-3;
    t3.left=NULL;
    t3.right=&t6;
    t4.val=3;
    t4.left=&t7;
    t4.right=&t8;
    t5.val=2;
    t5.left=NULL;
    t5.right=&t9;  
    t6.val=11;
    t6.left=NULL;
    t6.right=NULL; 
    t7.val=3;
    t7.left=NULL;
    t7.right=NULL; 
    t8.val=-2;
    t8.left=NULL;
    t8.right=NULL; 
    t9.val=1;
    t9.left=NULL;
    t9.right=NULL; */
    struct TreeNode t1,t2,t3,t4,t5;
    t1.val=1;
    t1.left=&t2;
    t1.right=NULL;
    t2.val=2;
    t2.left=&t3;
    t2.right=NULL;  
    t3.val=3;
    t3.left=&t4;
    t3.right=NULL;
    t4.val=4;
    t4.left=&t5;
    t4.right=NULL;
    t5.val=5;
    t5.left=NULL;
    t5.right=NULL;  
    printf("%d\n", pathSum(&t1,5));
	  return 0;
}