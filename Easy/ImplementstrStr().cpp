/*Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle,0);
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}