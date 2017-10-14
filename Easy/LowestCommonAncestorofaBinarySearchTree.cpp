/*Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.*/

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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if(p->val==root->val) return p;
	else if(q->val==root->val) return q;
    else if(p->val>root->val&&q->val>root->val) return lowestCommonAncestor(root->right,p,q);
    else if(p->val<root->val&&q->val<root->val) return lowestCommonAncestor(root->left,p,q);
    else return root;
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
	t5.val = 27;
	t5.left = NULL;
	t5.right = NULL;	
	t6.val = 10;
	t6.left = NULL;
	t6.right = NULL;	
	struct TreeNode *ret=lowestCommonAncestor(&t1,&t6,&t5);
	printf("%d\n", ret->val);
	return 0;
}