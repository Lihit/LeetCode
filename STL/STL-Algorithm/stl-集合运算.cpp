#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;


void printV(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


//并集：set_union
//交集：set_intersection
//在该序列有，但另一个序列没有的元素:set_difference 
void main1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(11);
    v2.push_back(32);
    v2.push_back(93);

    vector<int> v3;
    v3.resize(v1.size() + v2.size());

    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printV(v3);
}

int main(int argc, char const *argv[])
{
    main1();
    return 0;
}