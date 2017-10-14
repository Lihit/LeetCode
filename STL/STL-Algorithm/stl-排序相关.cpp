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
//merge算法
void main1() {
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printV(v3);
}

//sort排序算法
class Teacher
{
public:
    Teacher(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void printT() {
        cout << this->name << ": " << this->age << endl;
    }
public:
    string name;
    int age;

};

bool Compare(Teacher &a, Teacher &b) {
    return a.age > b.age;
}
void main2() {
    vector<Teacher> vt;
    Teacher t1("jim", 32);
    Teacher t2("tom", 34);
    Teacher t3("jack", 30);
    Teacher t4("tony", 39);
    vt.push_back(t1);
    vt.push_back(t2);
    vt.push_back(t3);
    vt.push_back(t4);
    sort(vt.begin(), vt.end(), Compare);
    for (vector<Teacher> :: iterator it = vt.begin(); it != vt.end(); it++) {
        it->printT();
    }
}

//随机洗牌random_shuffle
void main3() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    random_shuffle(v1.begin(), v1.end());
    printV(v1);

    string str1 = "abcdefg";
    random_shuffle(str1.begin(), str1.end());
    cout << str1 << endl;
}

//倒序
void main4(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);    
    reverse(v1.begin(),v1.end());
    printV(v1);
}
int main(int argc, char const *argv[])
{
    main4();
    return 0;
}