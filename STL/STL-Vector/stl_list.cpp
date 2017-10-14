#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;

void main1() {
	list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i + 1);//尾部插入元素
	}
	cout << "list的大小：" << l.size() << endl;
	list<int>::iterator it = l.begin();
	while (it != l.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//链表的index序号是从0号位置开始的
	//在3号位置插入元素 让原来的3号位置变成4号位置
	it = l.begin();
	it++;
	it++;
	it++;
	l.insert(it, 100);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
}

//list的删除
void main2(){
	list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i + 1);//尾部插入元素
	}
	cout << "list的大小：" << l.size() << endl;	

	list<int>:: iterator it=l.begin();
	list<int>:: iterator it2=l.begin();
	it2++;
	it2++;
	it2++;
	l.erase(it,it2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	l.insert(l.begin(),100);
	l.insert(l.begin(),100);
	l.insert(l.begin(),100);
	l.erase(l.begin());
	l.remove(100);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
}
int main(int argc, char const *argv[])
{
	main2();
	return 0;
}