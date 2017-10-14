/*Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.*/


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int count = 1;
        while (true) {
            int tmp = count * pow(10, count - 1) * 9;
            if (n - tmp <= 0) break;
            n -= tmp;
            count++;
        }
        int n_tmp = pow(10, count - 1) + ceil(1.0 * n / count) - 1;
        int n_mod = n % count == 0 ? count : n % count;
        return (n_tmp / (int)pow(10, count - n_mod)) % 10;
    }
};

int main(int argc, char const *argv[])
{
    int tmp = pow(10, 3);
    Solution so;
    cout << so.findNthDigit(100) << endl;
    return 0;
}