//
// Created by wenshao on 18-3-27.
//

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <iostream>
#include <boost/ref.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h>

using namespace std;
using namespace boost;

//自愿申请即初始化RAII
class myclass{
public:
    char *p = nullptr;
public:
    myclass(const char *str){
        cout<<"create"<<endl;
        int length = strlen(str);
        p = new char[length+1];
        strcpy(p,str);
        p[length]='\0';
    }
    ~myclass(){
        cout<<"destroy"<<endl;
        delete[] p;
    }
};

void go(){
    char* p = new char[100];
    myclass mystr = "hello";//RAII避免内存泄漏，一般情况下，堆上内存当栈使用
}
int main(){
    go();
    return 0;
}