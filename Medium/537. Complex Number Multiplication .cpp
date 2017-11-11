/* Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:

Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:

Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

Note:

    The input strings will not have extra blank.
    The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        stringstream aa(a),bb(b);
        double a_real,a_img,b_real,b_img;
        char buff;
        aa>>a_real>>buff>>a_img>>buff;
        bb>>b_real>>buff>>b_img>>buff;
        double ret_real=a_real*b_real-a_img*b_img,ret_img=a_real*b_img+a_img*b_real;
        ostringstream os;
        os<<ret_real<<"+"<<ret_img<<"i";
        return os.str();

    }
};

int main(int argc, char const *argv[])
{

    return 0;
}