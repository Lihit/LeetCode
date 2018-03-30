//
// Created by wenshao on 18-3-20.
//

#include <boost/array.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace boost;
//boost::array
int main1(){
    array<int,5> barray = {1,2,3,4,5};
    barray[0] = 10;
    barray.at(4) = 20 ;
    int *p=barray.data();
    for(int i =0;i<barray.size();i++){
        cout<<barray[i]<<" "<<p[i]<<endl;
    }
    return 0;
}