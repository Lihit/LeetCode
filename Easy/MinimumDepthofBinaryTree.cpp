/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

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

int minDepth(struct TreeNode* root) {
    if(root==NULL) return 0;
    if(root->left!=	NULL && root->right!=NULL){
		int left=minDepth(root->left);
    	int right=minDepth(root->right);
    	return left<right?left+1:right+1;    	
    }
    else if(root->left==NULL && root->right!=NULL){
    	return 1+minDepth(root->right);
    }
	else if(root->left!=NULL && root->right==NULL){
    	return 1+minDepth(root->left);
    }    
    else{
    	return 1;
    }
}
int main(int argc, char const *argv[])
{
	
	return 0;
}