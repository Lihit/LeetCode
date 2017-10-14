#include "iostream"
using namespace std;
class parent
{
public:
	parent(int ma){
		this->a=ma;
	}
	virtual void printa(){
		cout<<"i am parent"<<endl;
	}
public:
	int a;

};


class child:public parent
{
public:
	child(int mb):parent(2)
	{
		this->b=mb;
	}
	virtual void printa(){
		cout<<"i am child"<<endl;
	}
public:
	int b;

};

void objplay(parent * obj){
	obj->printa();
}
int main111(int argc, char const *argv[])
{
	int a;
	long b;
	cin>>a;
	cin>>b;
	parent p(4);
	child c(55);
	objplay(&p);
	objplay(&c);
	return 0;
}

int main(){
	double a=5.5,b=2.5;
	cout<<(int)a+b/b<<endl;
	int r=5;
	int aa=7,bb=5;
	printf("%d\n", bb=bb/aa);
	if(a){printf("hello \n");}
}