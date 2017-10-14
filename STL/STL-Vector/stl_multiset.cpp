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

void main1(){
	multiset<int> set1;
	int tmp=0;
	cout<<"请输入multiset集合的值：";
	cin>>tmp;
	while(tmp!=0){
		set1.insert(tmp);
		cout<<"请输入multiset集合的值：";
		cin>>tmp;
	}
	//遍历
	for (multiset<int>::iterator it = set1.begin(); it != set1.end(); it++) {
		cout << *it << " ";
	}
	cout<<endl;
	//删除
	while(!set1.empty()){
		multiset<int>::iterator it=set1.begin();
		cout<<*it<<" ";
		set1.erase(it);
	}
}
int main(int argc, char const *argv[])
{
	main1();
	return 0;
}