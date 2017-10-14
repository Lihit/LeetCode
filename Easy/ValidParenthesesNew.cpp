#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string left="({[";
		string right=")}]";
		stack<char> stmp;
		for(int i=0;i<s.length();i++){
			if(left.find(s[i])!=-1) stmp.push(s[i]);
			else{
				if(stmp.empty()) return false;
				char ctmp=stmp.top();
				stmp.pop();
				if(ctmp!=left[right.find(s[i])]) return false;
			}
		}
		return stmp.empty();
    }
};
int main(int argc, char const *argv[])
{
	Solution sol;
	string s="((";
	cout<<sol.isValid(s)<<endl;
	return 0;
}