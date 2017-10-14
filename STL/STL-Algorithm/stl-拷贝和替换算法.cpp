#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;


void printV(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//拷贝
void main1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);

    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    printV(v2);

}

//替换repalce
bool great_equal(int &a) {
    return a >= 5;
}
void main2() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(7);

    replace(v1.begin(), v1.end(), 7, 100);
    printV(v1);

    replace_if(v1.begin(), v1.end(), great_equal, 1);
    printV(v1);
}

//交换
void main3() {
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    swap(v1, v2);
    printV(v1);
}
int main(int argc, char const *argv[])
{
    main3();
    return 0;
}