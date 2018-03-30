//
// Created by wenshao on 18-3-20.
//

#include <boost/bind.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace boost;
//绑定函数的默认值，继承二进制函数的所有内容
class add:public binary_function<int,int,void>{
public:
    void operator()(int i,int j)const{
        cout<<i+j<<endl;
    }
};

void newadd(int i,int j){
    cout<<i+j<<endl;
}
int main_bind(){
    vector<int> myv={11,23,45};
    //for_each(myv.begin(),myv.end(),bind1st(add(),10));
    for_each(myv.begin(),myv.end(),bind(newadd,_1,2));
    for_each(myv.begin(),myv.end(),[](int i){cout<<i<<endl;});
    //bind 设置默认参数调用，函数副本机制
    return 0;
}