/*Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

int findNum(struct TreeNode* root, int k){
	int ret=0;
	if(root==NULL) return 0;
	if(root->val==k) return 1;
	if(k<root->val){
		ret=findNum(root->left,k);
	}else{
		ret=findNum(root->right,k);
	}
	return ret;
}
/*int findMaxNum(struct TreeNode* root){
	while(root->right) root=root->right;
	return root->val;
}*/

int findMinNum(struct TreeNode* root){
	while(root->left) root=root->left;
	return root->val;
}

bool findTarget(struct TreeNode* root, int k) {
	if(root==NULL) return false;
	bool ret=false;
	int i=0;
    int Minnum=findMinNum(root);
	for(i=Minnum;i<=k/2;i++){
		if(i!=k-i&&findNum(root,i)&&findNum(root,k-i)){
			ret=true;
			break;
		}
	}
	return ret;
}
/*
    13
   / \
  9  20
    /  \
   15   7

*/
int main(int argc, char const *argv[])
{
	struct TreeNode t1,t2,t3,t4,t5;
	t1.val=13;
	t1.left=&t2;
	t1.right=&t3;
	t2.val=-9000000;
	t2.left=NULL;
	t2.right=NULL;	
	t3.val=20;
	t3.left=&t4;
	t3.right=&t5;
	t4.val=15;
	t4.left=NULL;
	t4.right=NULL;
	t5.val=27;
	t5.left=NULL;
	t5.right=NULL;	
	if(findTarget(&t1,40)){
		printf("find...\n");
	}else{
		printf("not found...\n");
	}
	return 0;
}