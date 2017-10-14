/*Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]*/

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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void helper(struct TreeNode* root,char ***ret,int* returnSize,int index){
	int slen=strlen((*ret)[index]);
	(*ret)[index]=(char*)realloc((*ret)[index],(slen+10)*sizeof(char));
	char *stmp=(char*)calloc(10,sizeof(char));
	sprintf(stmp,"%d",root->val);
	strcat((*ret)[index],stmp);
	if(root->left==NULL && root->right==NULL) return;
	else if(root->left!=NULL && root->right==NULL){
		(*ret)[index]=(char*)realloc((*ret)[index],sizeof(char)*(strlen((*ret)[index])+3));
		strcat((*ret)[index],"->");
		helper(root->left,ret,returnSize,index);
	}
	else if(root->left==NULL && root->right!=NULL){
		(*ret)[index]=(char*)realloc((*ret)[index],sizeof(char)*(strlen((*ret)[index])+3));
		strcat((*ret)[index],"->");
		helper(root->right,ret,returnSize,index);
	}
	else{
		(*ret)[index]=(char*)realloc((*ret)[index],sizeof(char)*(strlen((*ret)[index])+3));
		strcat((*ret)[index],"->");
		*returnSize+=1;
		*ret=(char**)realloc(*ret,(*returnSize)*sizeof(char*));
		(*ret)[*returnSize-1]=(char*)calloc(strlen((*ret)[index])+1,sizeof(char));
		strcpy((*ret)[*returnSize-1],(*ret)[index]);
		int tmp=*returnSize-1;
		helper(root->left,ret,returnSize,index);
		helper(root->right,ret,returnSize,tmp);
	}
	
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
	char **ret=NULL;
    if(root==NULL) return NULL;
    else{
    	ret=(char**)calloc((*returnSize+1),sizeof(char*));
    	ret[0]=(char*)calloc(0,sizeof(char));
    	*returnSize+=1;
    	helper(root,&ret,returnSize,0);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	struct TreeNode t1, t2, t3, t4, t5,t6;
	t1.val = 13;
	t1.left = &t2;
	t1.right = &t3;
	t2.val = 9;
	t2.left = NULL;
	t2.right = &t6;
	t3.val = 20;
	t3.left = &t4;
	t3.right = &t5;
	t4.val = 15;
	t4.left = NULL;
	t4.right = NULL;
	t5.val = 233;
	t5.left = NULL;
	t5.right = NULL;	
	t6.val = 10;
	t6.left = NULL;
	t6.right = NULL;
	int returnSize=0;
	char **ret=binaryTreePaths(&t1,&returnSize);
	for(int i=0;i<returnSize;i++){
		printf("%s\n", ret[i]);
	}
	return 0;
}