/*Given a binary search tree and the lowest and highest boundaries as L and R,
trim the tree so that all its elements lies in [L, R] (R >= L). You might need
to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
    1
   / \
  0   2

  L = 1
  R = 2

Output:
    1
      \
       2
Example 2:
Input:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output:
      3
     /
   2
  /
 1*/

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

struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if (root == NULL) return NULL;
    if (root->val < L) return trimBST(root->right, L, R);
    else if (root->val > R) return trimBST(root->left, L, R);
    else {
      if (root->left != NULL) {
        if (root->left->val < L) root->left = root->left->right;
        else if (root->left->val > R) root->left = root->left->left;
      }
      if (root->right != NULL) {
        if (root->right->val < L) root->right = root->right->right;
        else if (root->right->val > R) root->right = root->right->left;
      }
      root->left = trimBST(root->left, L, R);
      root->right = trimBST(root->right, L, R);
      return root;
    }
}

int main(int argc, char const *argv[])
{

  return 0;
}