#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main1() {
	vector<int> v1;
	cout << "length:" << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	cout << "length:" << v1.size() << endl;

	cout << "头部元素:" << v1.front() << endl;
	//修改头部元素的值
	//函数返回值当左值，应该返回引用
	v1.front() = 11;

	//获取尾部元素
	while (v1.size() > 0) {
		cout << "尾部元素:" << v1.back() << endl;
		v1.pop_back();
	}


}

void main2() {
	vector<int> tmp(10, 1);
	for (int i = 0; i < 10; i++) {
		cout << tmp[i];
	}
}
int main(int argc, char const *argv[])
{
	main2();
	return 0;
}