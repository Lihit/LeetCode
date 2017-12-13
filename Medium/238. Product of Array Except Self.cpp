//
// Created by wenshao on 2017/12/13.
//

/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <cmath>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numslen=nums.size();
        vector<int> ret(numslen,0),beginV(numslen,1),lastV(numslen,1);
        for(int i=1;i<numslen;i++){
            beginV[i]=beginV[i-1]*nums[i-1];
            lastV[numslen-1-i]=lastV[numslen-i]*nums[numslen-i];
        }
        for (int j = 0; j < numslen; ++j) {
            ret[j]=beginV[j]*lastV[j];
        }
        return ret;
    }
};

int main() {
    return 0;
}