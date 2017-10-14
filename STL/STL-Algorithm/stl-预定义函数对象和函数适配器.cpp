#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

//plus预定义好的函数对象 能实现不同类型数据的+运算
//实现了数据类型和算法的分离==>通过函数对象技术的实现


void main1() {
    plus<int> intAdd;
    int x = 10;
    int y = 20;
    int z = intAdd(x, y);
    cout << "z: " << z << endl;
    //相加
    plus<string> stringAdd;
    string s1 = "aaa";
    string s2 = "bbb";
    string s3 = stringAdd(s1, s2);
    cout << "s3:" << s3 << endl;
    //排序
    vector<string> v1;
    v1.push_back("bbb");
    v1.push_back("aaa");
    v1.push_back("aaa");
    v1.push_back("aaa");
    v1.push_back("eee");
    v1.push_back("zzz");
    sort(v1.begin(), v1.end(), greater<string>());
    for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << endl;
    }

    //求aaa出现的次数
    //equal_to<string>() 有两个参数 left参数来自容器 right参数来自s2
    string sc = "aaa";
    int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
    cout << "num: " << num << endl;
}


class IsGreat
{
public:
    IsGreat(int i) {
        m_num = i;
    }
    bool operator()(int &num) {
        return num > m_num;
    }
private:
    int m_num;

};
void main2() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    int num1 = count(v1.begin(), v1.end(), 3);
    cout << "num1:" << num1 << endl;

    //用自己定义的谓词
    int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
    cout << "num2:" << num2 << endl;

    int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),2));
    cout << "num3:" << num3 << endl;


    //求奇数的个数
    int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(),2));
    cout << "num4:" << num4 << endl;

    //求偶数的个数
    int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(),2)));
    cout << "num5:" << num5 << endl;    
 
}
int main(int argc, char const *argv[])
{
    main2();
    return 0;
}