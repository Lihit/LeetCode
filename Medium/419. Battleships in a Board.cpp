// Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's,
//  empty slots are represented with '.'s. You may assume the following rules:

// You receive a valid board, made of only battleships or empty slots.
// Battleships can only be placed horizontally or vertically. In other words, they can only be made of
// the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
// At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
// Example:
// X..X
// ...X
// ...X
// In the above board there are 2 battleships.
// Invalid Example:
// ...X
// XXXX
// ...X
// This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
//
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int boardHeight = board.size();
        int ret=0;
        for (int i = 0; i < boardHeight; ++i)
        {
            int boardWidth=board[i].size();
            for (int j = 0; j < boardWidth; ++j)
            {
                //cout the head of the battleship
                if(board[i][j]=='X' && (i==0 || board[i-1][j]!='X') && (j==0 || board[i][j-1]!='X')) ret++;
            }
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    cout << "hello world" << endl;
    return 0;
}