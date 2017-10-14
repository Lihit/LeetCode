#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

//默认情况下是从小到大排序的
void main1() {
	set<int> set1;
	for (int i = 0; i < 5; i++) {
		int tmp = rand();
		set1.insert(tmp);
	}
	set1.insert(100);
	set1.insert(100);
	set1.insert(100);
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
		cout << *it << " ";
	}

	while (!set1.empty()) {
		set<int>::iterator it = set1.begin();
		cout << *it << " ";
		set1.erase(set1.begin());
	}
}

void main2() {
	set<int> set1;
	set<int, less<int> > set2;
	set<int, greater<int> > set3;
	for (int i = 0; i < 5; i++) {
		int tmp = rand();
		set3.insert(tmp);
	}
	set3.insert(100);
	set3.insert(100);
	set3.insert(100);
	for (set<int>::iterator it = set3.begin(); it != set3.end(); it++) {
		cout << *it << " ";
	}
}


class Student
{
public:
	Student(const char *name, int age) {
		strcpy(this->name, name);
		this->age = age;
	}
public:
	int age;
	char name[64];
};

//仿函数
struct FuncStudent
{
	bool operator()(const Student &left, const Student &right) {
		return left.age < right.age;
	}
};

void main3() {
	set<Student, FuncStudent> set1;
	Student s1("s1",31);

	Student s2("s2",31);
	Student s3("s3",33);
	Student s4("s4",34);
	pair<set<Student, FuncStudent>:: iterator, bool> pair1=set1.insert(s1);
	if(pair1.second==true){
		cout<<"插入成功"<<endl;
	}else{
		cout<<"插入失败"<<endl;
	}
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	for (set<Student, FuncStudent>::iterator it = set1.begin(); it != set1.end(); it++) {
		cout << it->name << "\t"<<it->age<<endl;;
	}	
}


int main(int argc, char const *argv[])
{
	main3();
	return 0;
}