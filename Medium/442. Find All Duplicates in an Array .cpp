/*Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        if(nums.size()==0) return ret;
        sort(nums.begin(),nums.end());
        int tmp=nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]==tmp) ret.push_back(nums[i]);
            else tmp=nums[i];
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> tmp;
    tmp[10]=10;
    cout<<tmp.size()<<endl;
    return 0;
}

