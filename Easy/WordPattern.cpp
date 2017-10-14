/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.*/


#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int plen = pattern.length(), slen = str.length();
		if (plen == 0) return false;
		map<char, string> map1;
		map<string, char> map2;
		int index1 = 0, index2 = str.find(" ", index1);
		index2 = index2 == -1 ? slen : index2;
		map1[pattern[0]] = str.substr(index1, index2 - index1);
		map2[str.substr(index1, index2 - index1)]=pattern[0];
		for (int i = 1; i < plen; i++) {
			map<char, string>::iterator it = map1.find(pattern[i]);
			index1 = index2 + 1;
			index2 = str.find(" ", index1);
			index2 = index2 == -1 ? slen : index2;
			if (index2 <= index1) return false;
			if (it != map1.end()) {
				if (it->second != str.substr(index1, index2 - index1)) return false;
			}
			else {
				map<string, char>::iterator it2 = map2.find(str.substr(index1, index2 - index1));
				if(it2==map2.end()){
					map1[pattern[i]] = str.substr(index1, index2 - index1);
					map2[str.substr(index1, index2 - index1)]=pattern[i];
				}	
				else return false;
			}
		}
		return index2 == slen;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	string pattern = "a";
	string str = "dog";
	if (s.wordPattern(pattern, str)) cout << "hello" << endl;
	return 0;
}