//
// Created by wenshao on 2017/12/17.
//

/*
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   /
  3
 /
4
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].

*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode *root,vector<vector<string>>& vtmp,int deep,int index){
        if(root==NULL) return;
        if(deep>=vtmp.size()) vtmp.push_back(vector<string>(pow(2,deep),""));
        vtmp[deep][index]=to_string(root->val);
        helper(root->left,vtmp,++deep,2*index);
        helper(root->right,vtmp,deep,2*index+1);
    }

    vector<vector<string>> printTree(TreeNode *root) {
        cout<<pow(2,0)<<endl;
        vector<vector<string>> vtmp;
        helper(root,vtmp,0,0);
        int treeDeep=vtmp.size(),count=0;
        vector<vector<string>> ret(treeDeep,vector<string>(pow(2,treeDeep)-1,""));
        for(int i=treeDeep-1;i>=0;i--){
            for(int j=0;j<vtmp[i].size();j++){
                ret[i][pow(2,count)-1+pow(2,count+1)*j]=vtmp[i][j];
            }
            count++;
        }
        return ret;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main() {
    Solution s;
    TreeNode* root=new TreeNode(10);
    TreeNode* r1=new TreeNode(11);
    TreeNode* r2=new TreeNode(1222);
    TreeNode* r3=new TreeNode(123);
    TreeNode* r4=new TreeNode(2222);
    root->left=r1;
    root->right=r2;
    r2->right=r3;
    r3->left=r4;
    vector<vector<string>> ret =s.printTree(root);
    return 0;
}