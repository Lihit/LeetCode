/*Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1:
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        vector<vector<int>> dirs{{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) q.push(make_pair(i, j));
                else matrix[i][j]=INT_MAX;
            }
        }

        while(!q.empty()){                
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto a:dirs){
                if(x+a[0]<matrix.size()&&x+a[0]>=0&&y+a[1]<matrix[0].size()&&y+a[1]>=0){
                    if(matrix[x][y]+1 < matrix[x+a[0]][y+a[1]]){
                        q.push(make_pair(x+a[0],y+a[1]));
                        matrix[x+a[0]][y+a[1]] = matrix[x][y]+1;
                    }
                }
            }
            
        }
        return matrix;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> matrix(4, vector<int>(4, 1));
    matrix[1][1] = 0;
    matrix[3][3] = 0;
    vector<vector<int>> ret = s.updateMatrix(matrix);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}