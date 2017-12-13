#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
   int x=0;
   //int *p=&x++;
   //cout<<*p<<endl;
   int *p1=&(++x);
   cout<<*p1<<endl;

   return 0;
}