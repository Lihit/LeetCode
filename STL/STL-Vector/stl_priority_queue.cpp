#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

void main1() {
	priority_queue<int> p1;//默认情况下是最大值优先及 队列
	priority_queue<int, vector<int>, less<int> > p2; //提前定义好的预定义函数，记得加空格，不然编译会出错 
	priority_queue<int, vector<int>, greater<int> > p3; //最小值优先级对列 
	p1.push(33);
	p1.push(11);
	p1.push(55);
	p1.push(22);
	cout<<"队头元素："<<p1.top()<<endl;
	cout<<"队列的大小:"<<p1.size()<<endl;
	while (p1.size()>0) {
		cout << p1.top() << " ";
		p1.pop();

	}
	cout<<endl<<"最小值优先级对列"<<endl;
	p3.push(33);
	p3.push(11);
	p3.push(55);
	p3.push(22);
	cout<<"队头元素："<<p3.top()<<endl;
	cout<<"队列的大小:"<<p3.size()<<endl;
	while (p3.size()>0) {
		cout << p3.top() << " ";
		p3.pop();

	}

}
int main(int argc, char const *argv[])
{
	main1();
	return 0;
}