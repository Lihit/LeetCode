/*Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    bool isSquareNum(int num) {
        int tmp = (int)sqrt(num);
        return tmp * tmp == num;
    }
    bool judgeSquareSum(int c) {
        if (isSquareNum(c)) return true;
        int tmp = sqrt(c);
        while (tmp) {
            if (isSquareNum(c-tmp*tmp)) return true;
            else tmp--;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.judgeSquareSum(29) << endl;
    return 0;
}