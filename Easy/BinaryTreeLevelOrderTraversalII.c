/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]*/

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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int getLevelOrderBottom(struct TreeNode* root, int*** ArrayRet, int** columnSizes, int length, int level) {
	if (root == NULL) return length;
	int size = length;
	if (level>size - 1) {
		*ArrayRet = realloc(*ArrayRet, sizeof(int*)*(size + 1));
		(*ArrayRet)[level]= calloc(1, sizeof(int));
		memset((*ArrayRet)[level], 0, sizeof(int));
		*columnSizes = realloc(*columnSizes, sizeof(int)*(size + 1));
		(*columnSizes)[level] = 0;
		size++;
	}
	(*ArrayRet)[level] = realloc((*ArrayRet)[level], sizeof(int)*((*columnSizes)[level] + 1));
	(*ArrayRet)[level][(*columnSizes)[level]] = root->val;
	(*columnSizes)[level] += 1;
	size = getLevelOrderBottom(root->left, ArrayRet, columnSizes, size, level + 1);
	size = getLevelOrderBottom(root->right, ArrayRet, columnSizes, size, level + 1);
	return size;
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
	int **ArrayRet = calloc(1, sizeof(int *));
	ArrayRet[0] = calloc(1, sizeof(int));
	memset(ArrayRet[0], 0, sizeof(int));
	*returnSize = getLevelOrderBottom(root, &ArrayRet, columnSizes, 0, 0);
	int **ret = calloc(*returnSize, sizeof(int *));
    int i=0;
    for(i=0;i<*returnSize;i++){
    	ret[i]=calloc((* columnSizes)[*returnSize-i-1],sizeof(int));
    	memcpy(ret[i],ArrayRet[*returnSize-i-1],sizeof(int)*(* columnSizes)[*returnSize-i-1]);
    }
    int k=0,j=* returnSize-1;
    while(k<j){
    	int tmp=(* columnSizes)[k];
    	(* columnSizes)[k++]=(* columnSizes)[j];
    	(* columnSizes)[j--]=tmp;
    }
    return ret;
}
int main(int argc, char const *argv[])
{
	struct TreeNode t1, t2, t3, t4, t5;
	t1.val = 1;
	t1.left = &t2;
	t1.right = &t3;
	t2.val = 9;
	t2.left = &t3;
	t2.right = NULL;
	t3.val = 20;
	t3.left = &t4;
	t3.right = NULL;
	t4.val = 15;
	t4.left = &t5;
	t4.right = NULL;
	t5.val = 27;
	t5.left = NULL;
	t5.right = NULL;
	int returnSize=0;	
	int *columnSizes=calloc(1,sizeof(int));
	int **ArrayRet=levelOrderBottom(&t1,&columnSizes,&returnSize);
	int i=0,j=0;
	for(i=0;i<returnSize;i++){
		for(j=0;j<columnSizes[i];j++){
			printf("%d ",ArrayRet[i][j] );
		}
		printf("\n");
	}
	return 0;
}