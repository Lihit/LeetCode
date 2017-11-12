/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        vector<int> tmp(32);
        for(int i=1;i<=num;i++){
            if(tmp[31]==0){
                ret.push_back(ret[i-1]+1);
            }else{
                int count=0,flag=1;
                for(int j=31;i>=0;j--){
                    if(tmp[j]+flag==2){
                        tmp[j]=0;
                        count++;
                        flag=1;
                    }
                    else{
                        tmp[j]=flag;
                        break;
                    }
                }
                ret.push_back(ret[i-1]-count+1);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ret=s.countBits(5);
    for (int i = 0; i < ret.size(); ++i)
    {
        cout<<ret[i]<<endl;
    }
    return 0;
}