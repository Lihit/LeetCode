/*TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns
 a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode
algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

*/


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count = 0;
    unordered_map<int, unordered_map<string, string> > myDict;
    unordered_map<int, unordered_map<string, string> > myDict_rev;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int len = longUrl.size();
        if (myDict.find(len) != myDict.end()) {
            unordered_map<string, string> tmp = myDict[len];
            if (tmp.find(longUrl) != tmp.end()) {
                return tmp[longUrl];
            }
        }
        count++;
        string shortUrl = "";
        while (count > 0) {
            shortUrl += dict[count % 62];
            count /= 62;
        }
        unordered_map<string, string> map1;
        map1[longUrl] = shortUrl;
        myDict[len] = map1;
        unordered_map<string, string> map2;
        map2[shortUrl] = longUrl;
        myDict_rev[shortUrl.size()] = map2;
        return shortUrl;

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return myDict_rev[shortUrl.size()][shortUrl];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.encode("http://www.baidu.com")<<endl;
    return 0;
}