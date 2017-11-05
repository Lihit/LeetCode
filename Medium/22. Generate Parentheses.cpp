/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
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
    void helper(vector<string> &v,int leftNum,int rightNum,string &tmp){
        if(leftNum==0&&rightNum==0){
            v.push_back(tmp);
        }
        else if(leftNum>=rightNum){
            tmp+="(";
            helper(v,leftNum-1,rightNum,tmp);
        }
        else{
            if(leftNum==0){
                tmp+=")";
                helper(v,leftNum,rightNum-1,tmp);
            }
            else{
                string s1=tmp,s2=tmp;
                s1+="(";
                helper(v,leftNum-1,rightNum,s1);
                s2+=")";
                helper(v,leftNum,rightNum-1,s2);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s;
        helper(ret,n,n,s);
        return ret;
    }
};

void printV(vector<string> ret){
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<endl;
    }
}
int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> ret=s.generateParenthesis(2);
    printV(ret);
    return 0;
}