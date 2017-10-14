/*You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs
 that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char* tree2str(struct TreeNode* t) {
    if(t==NULL) return "";
    char *tmp=NULL;
    if(t->left==NULL && t->right==NULL){
      tmp=calloc(32,sizeof(char));
      sprintf(tmp,"%d\0",t->val);
      return tmp;
    }
    else if(t->left!=NULL && t->right==NULL){
        char *lefttmp=tree2str(t->left);
        tmp=calloc(strlen(lefttmp)+35,sizeof(char));
        sprintf(tmp,"%d(%s)\0",t->val,lefttmp);
        if(lefttmp!=NULL) free(lefttmp);
    }
    else if(t->left==NULL && t->right!=NULL){
        char *righttmp=tree2str(t->right);
        tmp=calloc(strlen(righttmp)+35,sizeof(char));
        sprintf(tmp,"%d()(%s)\0",t->val,righttmp);
        if(righttmp!=NULL) free(righttmp);
    }  
    else if(t->left!=NULL && t->right!=NULL){
        char *lefttmp=tree2str(t->left);
        char *righttmp=tree2str(t->right);
        tmp=calloc(strlen(lefttmp)+strlen(righttmp)+35,sizeof(char));
        sprintf(tmp,"%d(%s)(%s)\0",t->val,lefttmp,righttmp);
        if(lefttmp!=NULL) free(lefttmp);
        if(righttmp!=NULL) free(righttmp);
    }    
    return tmp;
}

int main(int argc, char const *argv[])
{
/*  char *tmp=calloc(100,sizeof(char));
  sprintf(tmp,"%d\0",-123);
  printf("%s\n%d", tmp,strlen(tmp));*/

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
    printf("%s\n", tree2str(&t1));
    return 0;
}
