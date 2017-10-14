/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret=0;
        for(string::reverse_iterator it=s.rbegin();it!=s.rend();it++){
            if(*it!=' ') ret++;
            else if(ret!=0) break;
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution so;
    string s="a dasda";
    cout<<so.lengthOfLastWord(s)<<endl;
    return 0;
}