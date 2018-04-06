//
// Created by wenshao on 2018/4/6.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

/*
upper_bound
upper_bound() returns an iterator to the elements in the given range which does not compare greater than the given value. The range given should be already sorted for upper_bound() to work properly. In other words it returns an iterator to the upper bound of the given element in the given sorted range.
 */
void main1(){
    int input[] = {1,2,2,3,4,4,5,6,7,8,10,45};
    vector<int> v(input, input+12);

    vector<int>::iterator it1 , it2;

    it1 = upper_bound(v.begin(), v.end(), 6);
    /* points to eight element in v */
    cout<<*it1<<endl;
    it2 = upper_bound(v.begin(), v.end(), 4);
    /* points to seventh element in v */
    cout<<*it2<<endl;
}
/*
lower_bound
lower_bound() returns an iterator to the elements in the given range which does no compare less than the given value. The range given should be already sorted for lower_bound() to work properly. In other words it returns an iterator to the lower bound of the given element in the given sorted range.
 */
void main2(){
    int input[] = {1,2,2,3,4,4,5,6,7,8,10,45};
    vector<int> v(input,input+12);

    vector<int>::iterator it1 , it2;

    it1 = lower_bound(v.begin(), v.end(), 4);
    /* points to fifth element in v */
    cout<<*it1<<endl;
    it2 = lower_bound (v.begin(), v.end(), 10);
    /* points to second last element in v */
    cout<<*it2<<endl;
}
int main() {
    main2();
    return 0;
}