#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
class showElement
{
public:
	showElement(){
		this->n=0;
	}
	void operator()(T &t) {
		n++;
		cout << t << endl;
	}
	void printN(){
		cout<<"n="<<n<<endl;
	}
protected:
private:
	int n;
};


//函数模板
template <typename T>
void FuncShowElement1(T &t) {
	cout << t << endl;
}

//普通函数
void FuncShowElement2(int t) {
	cout << t << endl;
}


void main1() {
	int a = 10;
	showElement<int> s;
	s(a);//函数对象（）的执行 很像一个函数
}
//函数对象是属于类对象，能突破函数的概念，能爆出调用状态信息
//函数对象的好处
void main2(){
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	for_each(v.begin(),v.end(),showElement<int>());//匿名函数对象 匿名仿函数
	for_each(v.begin(),v.end(),FuncShowElement2);//通过回调函数 谁使用for_each 谁去填写回调函数的入口地址

	showElement<int> s2;
	//函数对象做函数参数
	for_each(v.begin(),v.end(),s2);//匿名函数对象 匿名仿函数
	s2.printN();
	cout<<"通过for_each算法的返回值来看调用的次数"<<endl;
	//for_each返回了一个函数对象
	s2=for_each(v.begin(),v.end(),s2);//匿名函数对象 匿名仿函数
	s2.printN();	

}

//一元谓词
template <typename T>
class IsDiv
{
public:
	IsDiv(T &divisor){
		this->divisor=divisor;
	}
	bool operator()(T &t){
		return t%divisor==0;
	}
private:
	T divisor;
};
void main3(){
	vector<int>v;
	for(int i=1;i<10;i++){
		v.push_back(i);
	}	
	int a=4;
	IsDiv<int> myDiv(a);
	//find_if(v.begin(),v.end(),myDiv);
	vector<int>::iterator it=find_if(v.begin(),v.end(),IsDiv<int>(a));
	if(it==v.end()){
		cout<<"容器中没有值被4整除的元素"<<endl;
	}
	else{
		cout<<"第一个整除的元素是："<<*it<<endl;
	}
}
int main(int argc, char const *argv[])
{
	main3();
	return 0;
}