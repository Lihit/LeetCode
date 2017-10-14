#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void main1(){
	queue<int> q;
	for (int i = 0; i < 10; i++) {
		q.push(i + 1);
	}	
	cout<<"队头元素："<<q.front()<<endl;
	cout<<"队列大小："<<q.size()<<endl;
	while (!q.empty()) {
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();

	}
}

class Teacher
{
public:
	int age;
	char name[256];
public:
	void printA() {
		cout << "age:" << age << endl;
	}

};

void main2(){
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);
	while (!q.empty()) {
		Teacher tmp = q.front();
		tmp.printA();
		q.pop();
	}
}
int main(int argc, char const *argv[])
{
	main2();
	return 0;
}