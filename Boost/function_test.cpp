//
// Created by wenshao on 18-3-20.
//

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h>

using namespace std;
using namespace boost;

int main1(){
    boost::function<int(char*)> fun = atoi;
    cout<<fun("123")+fun("234")<<endl;
    fun = strlen;
    cout<<fun("123")+fun("234")<<endl;
    return 0;
}

int main2(){
    boost::function<int(char*)> fun = atoi;
    cout<<fun("123")+fun("234")<<endl;
    fun = boost::bind(strcmp,"abc",_1);
    cout<<fun("123")<<endl;
    cout<<fun("abc")<<endl;
    return 0;
}

class manage{
public:
    void allstart(){
        for(int i=0;i<10;i++){
            if(workid){
                workid(i);
            }
        }
    }
    void setcallback(boost::function<void (int)> newid){//绑定调用
        workid = newid;
    }
public:
    boost::function<void (int)> workid;
};
class worker{
public:
    int id;
public:
    void run(int toid){
        id = toid;
        cout<<id<<"working..."<<endl;
    }
};

int main(){
    manage m;
    worker w;
    //类的成员函数调用　需要穿进去一个对象
    m.setcallback(boost::bind(&worker::run,&w,_1));
    m.allstart();
    return 0;
}