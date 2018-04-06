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

template <class T>
class myp{
public:
    myp(){

    }
    myp(T* t){
        p = t;
    }
    ~myp(){
        if(p!= nullptr){
            delete p;
        }
    }
    T operator*(){
        return *p;
    }
private:
    T *p = nullptr;
};

class Mytest{
public:
    Mytest(){
        cout<<"create"<<endl;
    }
    ~Mytest(){
        cout<<"delete"<<endl;
    }
};

void run(){
    myp<Mytest> p(new Mytest);//智能指针，自动释放
}
int main(){
    run();
    return 0;
}
