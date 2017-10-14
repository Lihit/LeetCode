/*Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).*/

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

void helper(struct TreeNode* root, int **ret,int *returnSize,int *maxCount, int *count, int *preVal){
	if(root==NULL) return;
	helper(root->left,ret,returnSize,maxCount,count,preVal);
	if(*preVal==INT_MIN) *preVal=root->val;
	if(root->val==*preVal){
		*count+=1;
	}
	else{
		if(*count>*maxCount){
			(*ret)[0]=*preVal;
			*returnSize=1;
			*maxCount=*count;
		}
		else if(*count==*maxCount){
			*ret=(int*)realloc(*ret,(*returnSize+1)*sizeof(int));
			(*ret)[*returnSize]=*preVal;
			*returnSize+=1;
		}
		*count=1;
		*preVal=root->val;
	}
	helper(root->right,ret,returnSize,maxCount,count,preVal);
}

int* findMode(struct TreeNode* root, int* returnSize) {
	if(root==NULL) return NULL;
    int *ret=(int *)calloc(1,sizeof(int));
    int maxCount=0,count=0,preVal=INT_MIN;
    helper(root,&ret,returnSize,&maxCount,&count,&preVal);
    if(maxCount==count){
    	ret=(int*)realloc(ret,(*returnSize+1)*sizeof(int));
    	ret[*returnSize]=preVal;
    	*returnSize+=1;
    }
    else if(maxCount<count){
    	ret[0]=preVal;
    	*returnSize=1;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	struct TreeNode t1, t2, t3, t4, t5,t6;
	t1.val = 15;
	t1.left = &t2;
	t1.right = &t3;
	t2.val = 14;
	t2.left = NULL;
	t2.right = &t6;
	t3.val = 21;
	t3.left = &t4;
	t3.right = &t5;
	t4.val = 20;
	t4.left = NULL;
	t4.right = NULL;
	t5.val = 233;
	t5.left = NULL;
	t5.right = NULL;	
	t6.val = 14;
	t6.left = NULL;
	t6.right = NULL;
	int returnSize=0;
	int *ret=findMode(&t1,&returnSize);
	for(int i=0;i<returnSize;i++){
		printf("%d\n", ret[i]);
	}
	return 0;
}