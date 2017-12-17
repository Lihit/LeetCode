//
// Created by wenshao on 2017/12/15.
//

/*
Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <cmath>

using namespace std;


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<string>> myDict;

    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i = 0; i < dict.size(); i++) {
            int slen = dict[i].size();
            myDict[slen].push_back(dict[i]);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int wordLen = word.size();
        if (myDict[wordLen].size() == 0) return false;
        else {
            vector<string> tmp=myDict[wordLen];
            for (int i = 0; i < tmp.size(); ++i) {
                string stmp=tmp[i];
                int count=0;
                for (int j = 0; j <stmp.size() ; ++j) {
                    if(stmp[j]!=word[j]) count++;
                    if(count>1) {
                        break;
                    }
                }
                if(count==1) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main() {
    MagicDictionary m;
    vector<string> dict = {"hello", "leetcode"};
    m.buildDict(dict);
    cout << m.search("hello") << endl;
    return 0;
}