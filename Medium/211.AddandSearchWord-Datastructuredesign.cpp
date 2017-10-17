/*Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.*/

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        int wordLen = word.size();
        unordered_map<int, vector<vector<int>>>::iterator it = myDict.find(wordLen);
        if (it == myDict.end()) {
            vector<vector<int>> strs;
            for (int i = 0; i < wordLen; i++) {
                vector<int> str(26, 0);
                str[word[i] - 'a'] = 1;
                strs.push_back(str);
            }
            myDict[wordLen] = strs;
        }
        else {
            for (int i = 0; i < wordLen; i++) {
                myDict[wordLen][i][word[i] - 'a'] = 1;
            }
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int wordLen = word.size();
        unordered_map<int, vector<vector<int>>>::iterator it = myDict.find(wordLen);
        if (it == myDict.end()) return false;
        else {
            for (int i = 0; i < wordLen; i++) {
                if (word[i] != '.') {
                    if (myDict[wordLen][i][word[i] - 'a'] == 0) return false;
                }
            }
        }
        return true;
    }
private:
    unordered_map<int, vector<vector<int>>> myDict;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
int main(int argc, char const *argv[])
{
    /*    vector<int> v(26, 0);
        for (auto a : v) {
            cout << a << endl;
            cout << v.size() << endl;
        }*/
    WordDictionary myDict;
    myDict.addWord("bad");
    myDict.addWord("dad");
    myDict.addWord("mad");
    /*search("pad") -> false
    search("bad") -> true
    search(".ad") -> true
    search("b..") -> true*/
    cout << myDict.search("bad") << endl;
    return 0;
}