/*Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numslen=nums.size(),ktmp=k%numslen;
        vector<int> tmp1(nums.begin(),nums.begin()+numslen-ktmp);
        tmp1.insert(tmp1.begin(),nums.begin()+numslen-ktmp,nums.end());
        nums=tmp1;
    }  
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;
    v.push_back(1);
/*    v.push_back(2);
    v.push_back(3);*/
    s.rotate(v,2);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}