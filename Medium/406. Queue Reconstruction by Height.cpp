/*Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ret;
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);};
        sort(people.begin(), people.end(), cmp);
        for (auto &p : people) {
            ret.insert(ret.begin() + p.second, p);
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}