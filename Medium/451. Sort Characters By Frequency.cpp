//
// Created by wenshao on 2017/12/7.
//

/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string ret;
        unordered_map<char,int> mymap;
        for(auto i:s){
            mymap[i]+=1;
        }
        map<int,string> myrmap;
        for(unordered_map<char,int>::iterator it =mymap.begin();it!=mymap.end();it++){
            string tmp(it->second,it->first);
            myrmap[it->second]+=tmp;
        }
        for(map<int,string>:: reverse_iterator it =myrmap.rbegin();it!=myrmap.rend();it++){
            ret+=it->second;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout<<s.frequencySort("Aabb");
    return 0;
}