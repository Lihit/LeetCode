/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> tmp;
        uint32_t ret = 0, count = 0;
        for (int i = 0; i < 32; i++) {
            tmp.push(n % 2);
            n /= 2;
        }
        while (!tmp.empty()) {
            ret += pow(2, count++) * tmp.top();
            tmp.pop();
        }
        return ret;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverseBits(12) << endl;
    return 0;
}