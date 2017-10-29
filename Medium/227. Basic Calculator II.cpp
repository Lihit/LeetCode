/*Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5*/

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        deque<int> sta;
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (s[i] == '+' || s[i] == '-') {
                    sta.push_back(s[i] - '0');
                    i++;
                } else {
                    int leftNum = sta.back(), rightNum = 0, count = 0, operSign = s[i++];
                    sta.pop_back();
                    stack<char> tmp;
                    while (s[i] <= '9' && s[i] >= '0' || s[i] == ' ') {
                        if (s[i] == ' ') {
                            i++;
                            continue;
                        }
                        else{
                            tmp.push(s[i]);
                            i++;
                        }
                        if (i >= s.size()) break;
                    }
                    while (!tmp.empty()) {
                        rightNum += (tmp.top() - '0') * pow(10, count);
                        count++;
                        tmp.pop();
                    }
                    if (operSign == '*') {
                        sta.push_back(leftNum * rightNum);
                    } else {
                        sta.push_back(leftNum / rightNum);
                    }
                }
            }
            else {
                stack<char> tmp;
                int count = 0, Num = 0;
                while (s[i] <= '9' && s[i] >= '0' || s[i] == ' ') {
                    if (s[i] == ' ') {
                        i++;
                        continue;
                    }
                    else{
                        tmp.push(s[i]);
                        i++;
                    }
                    if (i >= s.size()) break;
                }
                while (!tmp.empty()) {
                    Num += (tmp.top() - '0') * pow(10, count);
                    count++;
                    tmp.pop();
                }
                sta.push_back(Num);
            }
        }
        while (sta.size() > 1) {
            int leftNum = sta.front();
            sta.pop_front();
            int operSign = sta.front();
            sta.pop_front();
            int rightNum = sta.front();
            sta.pop_front();
            if (operSign + '0' == '+') {
                sta.push_front(leftNum + rightNum);
            }
            else if (operSign + '0' == '-') {
                sta.push_front(leftNum - rightNum);
            }
        }
        return sta.back();
    }
};
int main(int argc, char const *argv[])
{
    int num = pow(10, 0);
    cout << num << endl;
    return 0;
}