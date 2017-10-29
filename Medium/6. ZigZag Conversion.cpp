/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int slen = s.size();
        if(numRows==1) return s;
        string ret;
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = 0;; j++) {
                    if (2 * j * (numRows - 1) + i >= slen) break;
                    else {
                        ret += s[2 * j * (numRows - 1) + i];
                    }
                }
            } else {
                for (int j = 0;; j++) {
                    if (2 * j * (numRows - 1) + i >= slen) break;
                    else {
                        ret += s[2 * j * (numRows - 1) + i];
                        if (2 * j * (numRows - 1) + i + 2 * (numRows - 1 - i) >= slen) break;
                        else {
                            ret += s[2 * j * (numRows - 1) + i + 2 * (numRows - 1 - i)];
                        }
                    }
                }
            }
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    string s1 = "A";
    Solution s;
    cout << s.convert(s1, 1) << endl;
    return 0;
}