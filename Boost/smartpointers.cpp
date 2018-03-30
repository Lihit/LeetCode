//
// Created by wenshao on 18-3-28.
//

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <iostream>
#include <boost/ref.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <boost/weak_ptr.hpp>

using namespace std;
using namespace boost;


int mainI() {
    boost::scoped_ptr<int> p(new int);//自动释放内存
    *p = 1111;
    cout << *p.get() << endl;
    p.reset(new int);
    cout << *p.get() << endl;
    boost::scoped_ptr<int> pA(nullptr);//独占内存
    //pA = p;
    return 0;
}

int mainG() {
    boost::scoped_array<int> p(new int[10]);
    *p.get() = 1;
    p[3] = 2;
    p.reset(new int[5]);
    return 0;
}

void show(boost::shared_ptr<int> p) {
    cout << *p.get() << endl;
}

int mainS() {
    vector<boost::shared_ptr<int>> v;
    boost::shared_ptr<int> p1(new int);
    boost::shared_ptr<int> p2(new int);
    boost::shared_ptr<int> p3(p2);//拷贝
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for_each(v.begin(), v.end(), show);
    return 0;
}

class runclass {
public:
    int i = 0;
public:
    runclass(){

    }
    runclass(int num) : i(num) {
        cout << "i create" << endl;
    }

    ~runclass() {
        cout << "i delete" << endl;
    }

    void print() {
        cout << "i=" << i << endl;
    }
};

void testfun() {
    boost::shared_ptr<runclass> p1(new runclass(10));
    boost::shared_ptr<runclass> p2(p1);
    boost::shared_ptr<runclass> p3(p2);
    p1.reset(new runclass(111));
    p1->print();
    p2->print();
    p3->print();
}


void testfunarray(){
    boost::shared_array<runclass> p1(new runclass[5]);
    boost::shared_array<runclass> p2(p1);//内存共享
}

int main(){
    testfunarray();
    return 0;
}
