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
void main3(){
    enum flag{x=1,y=8,z=4};
    flag f1=flag(5);
    cout<<f1<<endl;
    flag f2=flag(x|y);
    cout<< f2<<endl;
}
int main(int argc, char const *argv[])
{
    cout<<sizeof(long)<<endl;
    main3();
    return 0;
}