#include <iostream>
#include <vector>
#include <string>

using namespace std;

int& use_count(){
    static int uc=0;
    return uc;
}
int main()
{
   cout<<++use_count()<<endl;
   cout<<++use_count()<<endl;
   cout<<++use_count()<<endl;
   //cout<<uc<<endl;
   return 0;
}