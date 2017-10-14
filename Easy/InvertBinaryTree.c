/*Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
	if(root==NULL) return NULL;
    if(root->left==	NULL && root->right==NULL){
    	return root;
    }
    struct TreeNode* tmp=root->left;
    root->left=invertTree(root->right);
    root->right=invertTree(tmp);
    return root;

}

void printTree(struct TreeNode* root){
	if(root==NULL) return;
	else{
		printf("%d\n", root->val);
		printTree(root->left);
		printTree(root->right);
	}
}
int main(int argc, char const *argv[])
{
	struct TreeNode t1,t2,t3,t4,t5;
	t1.val=3;
	t1.left=&t2;
	t1.right=&t3;
	t2.val=9;
	t2.left=NULL;
	t2.right=NULL;	
	t3.val=20;
	t3.left=&t4;
	t3.right=&t5;
	t4.val=15;
	t4.left=NULL;
	t4.right=NULL;
	t5.val=7;
	t5.left=NULL;
	t5.right=NULL;	
	printTree(&t1);
	struct TreeNode* root=invertTree(&t1);
	printTree(root);
	return 0;
}