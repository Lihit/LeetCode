#include <iostream>
#include <limits>
using namespace std;

void main1() {
    bool b = 1;
    cout << sizeof(b) << endl;
    wchar_t wt = 'h';
    cout << sizeof(wchar_t) << endl;
}

void main2() {
    cout << "largest float == " <<
         numeric_limits <int> :: min()
         << ", char is signed == " <<
         numeric_limits<char> :: is_signed
         << endl;
}
void main3() {
    enum flag {x = 1, y = 8, z = 4};
    flag f1 = flag(5);
    cout << f1 << endl;
    flag f2 = flag(x | y);
    cout << f2 << endl;
}
class Table
{
public:
    Table() {
        cout << "调用构造函数" << endl;
    }
    Table(const Table &obj) {
        cout << "调用拷贝构造函数" << endl;
    }
    ~Table() {
        cout << "调用析构函数" << endl;
    }

};
void f(int i)
{
    static Table tbl;
    if (i) {
        static Table tbl2;
    }
}
struct test
{

        int a=12;
};

int div111(int a,int b){
    if(b==0) throw b;
    return a/b;
}
void ft(){
    try{
        int ret=div111(12,0);
        cout<<ret<<endl;
        int ret11=div111(12,2);
        cout<<ret11<<endl;
    }catch(int){
        cout<<"divide 0"<<endl;
    }
    cout<<"nihao";
}
int main(int argc, char const *argv[])
{
    ft();
    int *a=new int[10];
    //int *b=a;
    delete []a;
    delete []a;
    cout<<"hello"<<endl;
    int _hello$=29;
    cout<<_hello$<<endl;
}