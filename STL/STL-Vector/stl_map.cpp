#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

//map元素的添加遍历删除等基本操作

void main1() {
	map<int, string> map1;
	//方法1
	map1.insert(pair<int, string>(1, "t1"));
	map1.insert(pair<int, string>(2, "t2"));

	//方法2
	map1.insert(make_pair(3, "t3"));
	map1.insert(make_pair(4, "t4"));

	//方法3
	map1.insert(map<int, string>::value_type(5, "t5"));
	map1.insert(map<int, string>::value_type(6, "t6"));

	//方法4
	map1[7] = "t7";
	map1[8] = "t8";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}

	while (!map1.empty()) {
		map<int, string>::iterator it = map1.begin();
		cout << it->first << "\t" << it->second << endl;
		map1.erase(it);
	}

}

void main2() {
	map<int, string> map1;
	//方法1
	map1.insert(pair<int, string>(1, "t1"));
	map1.insert(pair<int, string>(2, "t2"));

	//方法2
	map1.insert(make_pair(3, "t3"));
	map1.insert(make_pair(4, "t4"));

	//方法3
	map1.insert(map<int, string>::value_type(5, "t5"));
	map1.insert(map<int, string>::value_type(6, "t6"));

	//方法4
	map1[7] = "t7";
	map1[8] = "t8";
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}

	//map的查找
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end()) {
		cout << "key 100的值不存在" << endl;
	}
	else {
		cout << it2->first << "\t" << it2->second << endl;
	}
	cout<<map1[2]<<endl;
}
int main(int argc, char const *argv[])
{
	main2();
	return 0;
}