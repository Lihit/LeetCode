#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <ctime>

using namespace std;

template <typename T>
class SumAdd
{
private:

public:
	T operator()(T t1, T t2) {
		return t1 + t2;
	}
};

//二元对象
void main1() {
	vector<int> v1, v2;
	vector<int>v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
		cout << *it << " ";
	}
}


bool MyCompare(const int &a, const int &b) {
	return a < b;
}
//二元谓词
void main2() {
	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 100;
		v[i] = tmp;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//数组的排序
	sort(v.begin(), v.end(), MyCompare);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
}

//二元谓词在set中的应用
struct CompareNoCase
{
	bool operator()(const string &str1, const string &str2){
		string str1_;
		//全部变成小写
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), ::tolower); //预定义函数

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), ::tolower); //预定义函数
		return str1_ < str2_;
	}
};
void main3() {
	set<string> set1;
	set1.insert("aaa");
	set1.insert("bbb");
	set1.insert("ccc");
	set<string>::iterator it1 = set1.find("aaa");//默认是区分大小写的
	if (it1 != set1.end()) {
		cout << "查找到" << endl;
	}
	else {
		cout << "没有查找到" << endl;
	}

	//建立不区分大小写的
	set<string, CompareNoCase> set2;
	set2.insert("aaa");
	set2.insert("bbb");
	set2.insert("ccc");

	set<string, CompareNoCase> :: iterator it2 = set2.find("aAa");
	if (it2 != set2.end()) {
		cout << "查找到" << endl;
	}
	else {
		cout << "没有查找到" << endl;
	}
}
int main(int argc, char const *argv[])
{
	srand((unsigned)time(0));
	main3();
	return 0;
}