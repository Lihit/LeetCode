/*A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.*/


#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int Alen = A.size();
        if (Alen < 3) return 0;
        int status = 0, ret = 0, count = 0, i = 0;
        int diff = A[1] - A[0];
        for (i = 2; i < Alen; i++) {
            if (A[i] - A[i - 1] != diff) {
                count = i - status;
                status = i - 1;
                diff = A[i] - A[i - 1];
            }
            if (count >= 3) {
                ret += (count-1) * (count - 2) / 2;
            }
        }
        count = i - status;
        if (count >= 3) {
            ret += (count - 1) * (count - 2) / 2;
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}