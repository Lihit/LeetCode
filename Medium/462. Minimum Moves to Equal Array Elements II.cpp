//
// Created by wenshao on 2017/12/3.
//

/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

        Input:
[1,2,3]

Output:
2

Explanation:
        Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ret=0;
        sort(nums.begin(),nums.end());
        int numslen=nums.size();
        int midnum=0;
        if(numslen%2){
            midnum=nums[(numslen-1)/2];
        } else{
            midnum=(nums[numslen/2]+nums[numslen/2-1])/2;
        }
        for(auto p:nums){
            ret+=abs(p-midnum);
        }
        return ret;
    }
};
int main(){
    return 0;
}