/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/

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
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	if(numsSize<=0) return NULL;
    struct TreeNode* root=calloc(1,sizeof(struct TreeNode));
    root->val=nums[numsSize/2];
    root->left=sortedArrayToBST(nums,numsSize/2);
    root->right=sortedArrayToBST(nums+numsSize/2+1,(int)ceil(numsSize/2.0)-1);
    return root;
}
int main(int argc, char const *argv[])
{
	printf("%d\n",(int)ceil(4/2.0) );
	return 0;
}