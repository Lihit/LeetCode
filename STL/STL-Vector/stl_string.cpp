#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void main1() {
	string s1 = "hello world";
	string s2("nihao");
	string s3 = s2;
	string s4(10, 'a');
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
}

//string的遍历
void main2() {
	string s1 = "hello world";
	//数组的方式
	for (int i = 0; i < s1.length(); i++) {
		cout << s1[i];
	}
	cout << endl;

	//迭代器的方式
	for (string::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it;
	}
	cout << endl;

	//at()可以跑出异常
	try {
		for (int i = 0; i < s1.length(); i++) {
			cout << s1.at(i);
		}
	}
	catch (...) {
		cout << "发生异常" << endl;
	}

	cout << endl;
}

//字符串和指针的转化
void main3() {
	string s1 = "aaa";
	char buf[256] = {0};
	s1.copy(buf, 3, 0);
	cout << buf << endl;
}

//字符串的连接
void main4()
{
	string s1 = "aaa";
	string s2 = "bbb";
	s1 += s2;
	cout << s1 << endl;

	s1.append("hello");
	cout << s1 << endl;
}

//字符串的查找和替换
void main5(){
	string s1="shdiahsid osjadoajpfpdkfsdof  asd";
	int index=s1.find("h11si",0);
	cout<<index<<endl;
	string s11="111";
	string s22="111";
	if(s11==s22){
		cout<<"hello"<<endl;
	}
	s11.swap(s1);
	cout<<s1<<endl;

}
int main(int argc, char const *argv[])
{
	main5();
	return 0;
}