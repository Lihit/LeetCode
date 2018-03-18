//
// Created by wenshao on 2018/3/18.
//

/*
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.


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
class Solution {
public:
    void helper(vector<vector<int>> &graph, vector<vector<int>> &ret, vector<int> PathSave, int i, int N) {
        if (graph[i].size() == 0) return;
        for (int j = 0; j < graph[i].size(); j++) {
            PathSave.push_back(graph[i][j]);
            if(graph[i][j]==N-1){
                ret.push_back(PathSave);
            }else{
                helper(graph, ret, PathSave, graph[i][j], N);
            }
            PathSave.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> ret;
        vector<int> PathSave;
        PathSave.push_back(0);
        helper(graph,ret,PathSave,0,graph.size());
        return ret;
    }
};

int main() {
    int a = 12;
    a += a -= a *= a;
    cout << a << endl;
    return 0;
}