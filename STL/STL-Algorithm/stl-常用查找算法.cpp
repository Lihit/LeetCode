#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

void main1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(5);

    vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
    if (it == v1.end()) {
        cout << "没有重复元素" << endl;
    }
    else {
        cout << *it << endl;
    }

    int index = distance(v1.begin(), it);
    cout << index << endl;
}

void main2() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    bool ret = binary_search(v1.begin(), v1.end(), 7);
    if (ret) {
        cout << "找到了" << endl;
    }
    else {
        cout << "没找到" << endl;
    }
}

void main3() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    int num = count(v1.begin(), v1.end(), 3);
    cout << num << endl;
}


bool GreaterThree(int &n) {
    return n > 3;
}
void main4() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);

    int num = count_if(v1.begin(), v1.end(), GreaterThree) ;
    cout << num << endl;
    vector<int> ::iterator it = find_if(v1.begin(), v1.end(), GreaterThree);
    cout << *it << endl;
}

void main5() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);

    vector<int> ::iterator it = find(v1.begin(), v1.end(), 5);
    cout << distance(v1.begin(), it) << endl;
}
int main(int argc, char const *argv[])
{
    main4();
    return 0;
}