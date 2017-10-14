#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
void main1() {
	stack<int> s;
	for (int i = 0; i < 10; i++) {
		s.push(i + 1);
	}
	cout << "栈的大小：" << s.size() << endl;
	while (!s.empty()) {
		int tmp = s.top();
		cout << tmp << " ";
		s.pop();

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

void main2() {
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);
	while (!s.empty()) {
		Teacher tmp = s.top();
		tmp.printA();
		s.pop();
	}

}
int main(int argc, char const *argv[])
{
	main1();
	return 0;
}