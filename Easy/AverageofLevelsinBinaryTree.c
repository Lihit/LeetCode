/*Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
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

/*int* getTreeLayerVal(struct TreeNode* root, int layer,int* returnSize) {
	int leftcount=0;
	int rightcount=0;
	int *leftArray=NULL;
	int *rigthArray=NULL;
	int *returnArray=NULL;
	if(layer==1){
		if(root!=NULL){
			returnArray=(int*)malloc(sizeof(int));
			*returnArray=root->val;
			*returnSize=1;
		}
		return returnArray;
	}else{
		if(root->left!=NULL){
			leftArray=getTreeLayerVal(root->left,layer-1,&leftcount);
		}
		if(root->right!=NULL){
			rigthArray=getTreeLayerVal(root->right,layer-1,&rightcount);
		}
		*returnSize=leftcount+rightcount;
		returnArray=(int *)malloc(*returnSize*sizeof(int));
		memcpy(returnArray,leftArray,sizeof(int)*leftcount);
		memcpy(returnArray+leftcount,rigthArray,sizeof(int)*rightcount);
		return returnArray;
	}
    
}
double calAverage(int *returnArray,int size){
	double ret=0;
	int i=0;
	for(i=0;i<size;i++){
		ret+=returnArray[i];
	}
	return 1.0*ret/size;
}
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
	int count=0;
	double *averageArray=NULL;
	while(1){
		int arraysize=0;
		int *returnArray=getTreeLayerVal(root,count+1,&arraysize);
		if(arraysize==0){
			break;
		}
		averageArray=(double *)realloc(averageArray,sizeof(double)*(count+1));
		averageArray[count]=calAverage(returnArray,arraysize);
		count++;
		free(returnArray);
	}

	*returnSize=count;
    return averageArray;
}

    3
   / \
  9  20
    /  \
   15   7*/



int getAverage(struct TreeNode* root, long** sum, int** number, int length, int level) {
	if(root==NULL) return length;
	int size=length;
	if(level>size-1){
		*sum=realloc(*sum,sizeof(long)*(size+1));
		*number=realloc(*number,sizeof(int)*(size+1));
		(*sum)[level]=0;
		(*number)[level]=0;
		size++;
	}
	(*sum)[level]+=root->val;
	(*number)[level]+=1;
	size=getAverage(root->left,sum,number,size,level+1);
	size=getAverage(root->right,sum,number,size,level+1);
	return size;
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
	long* sum_in=calloc(0,sizeof(long));
	int* number_in=calloc(0,sizeof(int));
	int size=getAverage(root, &sum_in, &number_in, 0, 0);
	double *averageArray=calloc(size,sizeof(double));
	for(int i=0;i<size;i++){
		averageArray[i]=1.0*sum_in[i]/number_in[i];
	}
	*returnSize=size;
	return averageArray;
}

int getTreeLevel(struct TreeNode* root,int length,int level){
	if(root==NULL) return length;
	int size=length;
	if(level>size-1){
		size++;
	}
	size=getTreeLevel(root->left,size,level+1);
	size=getTreeLevel(root->right,size,level+1);
	return size;

}

int getTreeLayer(struct TreeNode* root){
	int deep=0;
	if(root==NULL) return deep;
	int leftdeep=getTreeLayer(root->left);
	int rightdeep=getTreeLayer(root->right);
	deep=leftdeep>=rightdeep?(leftdeep+1):(rightdeep+1);
	return deep;

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
	int returnSize=0;
	int i=0;
	double *returnArray=averageOfLevels(&t1,&returnSize);
	for(int i=0;i<returnSize;i++){
		printf("%0.2f \n", returnArray[i]);
	}
	printf("the level of tree is :%d\n", getTreeLayer(&t1));
	return 0;
}