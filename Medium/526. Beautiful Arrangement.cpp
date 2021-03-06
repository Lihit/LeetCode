/*Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation:

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<int> tmp;
        int ret = 0;
        for (int i = 1; i <= N; i++) {
            tmp.push_back(i);
        }
        ret = count(N, tmp);
        return ret;
    }
    int count(int n, vector<int> v) {
        if (n <= 0) return 1;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] % (i + 1) == 0 || (i + 1) % v[i] == 0) {
                swap(v[i],v[n-1]);
                ret+=count(n-1,v);
                swap(v[i],v[n-1]);
            }
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}