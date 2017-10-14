#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <list>
using namespace std;

void printV(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void ShowVector(int &n) {
    cout << n << " ";
}

class MyShowVector
{
public:
    MyShowVector() {
        num = 0;
    }
    void operator()(int &n) {
        num++;
        cout << n << " ";
    }
    void printNum() {
        cout << num << endl;
    }
private:
    int num;
};
void main1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    printV(v1);
    //使用回调函数的入口地址
    for_each(v1.begin(), v1.end(), ShowVector);
    cout << endl;
    //使用函数对象
    for_each(v1.begin(), v1.end(), MyShowVector());
    cout << endl;

    //使用函数对象
    MyShowVector ms = for_each(v1.begin(), v1.end(), MyShowVector());
    cout << endl;
    ms.printNum();
}

int increase(int i){
    return i;
}

void main2(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    printV(v1);

    //使用回调函数
    transform(v1.begin(),v1.end(),v1.begin(),increase);
    printV(v1);

    //使用预定义的函数对象
    transform(v1.begin(),v1.end(),v1.begin(),negate<int>());
    printV(v1);

    list<int> mylist;
    mylist.resize(v1.size());
    transform(v1.begin(),v1.end(),mylist.begin(),bind2nd(multiplies<int>(),10));
 
    //把运算结果直接输出到屏幕
    transform(mylist.begin(),mylist.end(),ostream_iterator<int>(cout," "),increase);
}
int main(int argc, char const *argv[])
{
    main2();
    return 0;
}