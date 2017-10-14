/*Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int carry = 0, alen = a.length(), blen = b.length();
        for (int i = 1; i <= fmax(alen, blen); i++) {
            int atmp = (alen - i) < 0 ? 0 : a[alen - i] - '0';
            int btmp = (blen - i) < 0 ? 0 : b[blen - i] - '0';
            ret.insert(0, 1, (atmp + btmp + carry) % 2 + '0');
            carry = (atmp + btmp + carry) / 2;
        }
        if (carry != 0) ret.insert(0, 1, '1');
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    string a = "11";
    string b = "11";
    Solution s;
    string ret = s.addBinary(a, b);
    cout << ret << endl;
    return 0;
}