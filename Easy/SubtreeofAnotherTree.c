/*Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.*/

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
struct TreeNode* findTreeVal(struct TreeNode* s,int num){
    if(s==NULL) return NULL;
    if(s->val==num) return s;
    struct TreeNode*lefttmp=findTreeVal(s->left,num);
    struct TreeNode*righttmp=findTreeVal(s->right,num);
    if(lefttmp) return lefttmp;
    else if(righttmp) return righttmp;
    else return NULL;
}
bool isEqual(struct TreeNode* tmp, struct TreeNode* t){
    if(tmp!=NULL&&t!=NULL) return (tmp->val==t->val)&&isEqual(tmp->left,t->left)&&isEqual(tmp->right,t->right);
    else if(tmp!=NULL&&t==NULL) return false;
    else if(tmp==NULL&&t!=NULL) return false;
    else return true;
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    struct TreeNode* tmp=findTreeVal(s,t->val);
    if(tmp==NULL) return false;
    else return isEqual(tmp,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
}
int main(int argc, char const *argv[])
{
  float a=log(4782968)/log(3);
  printf("%f\n",a );
  float b=round(log(4782968)/log(3));
  printf("%f\n",b );
  printf("%d\n",(float)(log(4782968)/log(3))==round(log(4782968)/log(3)));
  return 0;
}