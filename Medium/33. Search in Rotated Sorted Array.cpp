/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/


#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int helper(vector<int>& nums,int left,int right,int target){
        if(left==right){
            if(target==nums[left]) return left;
            else return -1;
        }
        else if(left > right) return -1;
        else{
            int mid=(left+right)/2;
            if(target==nums[mid]) return mid;
            if(target==nums[left]) return left;
            if(target==nums[right]) return right;
            if(nums[mid]>nums[left] && nums[mid]<nums[right]){
                if(target>nums[mid]){
                    return helper(nums,mid+1,right-1,target);
                }else{
                    return helper(nums,left+1,mid-1,target);
                }
            }
            else if(nums[mid]>nums[left] && nums[mid]>nums[right]){
                if(target>nums[mid]){
                    return helper(nums,mid+1,right-1,target);
                }else{
                    if(target>nums[left]) return helper(nums,left+1,mid-1,target);
                    else return helper(nums,mid+1,right-1,target);
                }
            }
            else{
                if(target<nums[mid]){
                    return helper(nums,left+1,mid-1,target);
                }
                else{
                    if(target>nums[right]) return helper(nums,left+1,mid-1,target);
                    else return helper(nums,mid+1,right-1,target);
                }
            }
        }

    }
    int search(vector<int>& nums, int target) { 
        return helper(nums,0,nums.size()-1,target);
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums={1,2,3,4,5};
    cout<<s.search(nums,2)<<endl;
    return 0;
}