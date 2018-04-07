//
// Created by wenshao on 2018/4/7.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;
/*
Following are some Modifying algorithms in Standard Template library that we will be covering :

copy and copy_n
fill and fill_n
move
transform
generate
swap
swap_ranges
reverse
reverse_copy
rotate
unique
unique_copy
 */

/*
copy and copy_n
copy method

This method copies the elements from the range defined by two iterators first and last into the range starting by the iterator first2.
 */
void main1(){
    vector<int> v1,v2;

    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(10);

    copy(v1.begin(), v1.end(), v2.begin());
}
/*
 copy_n method

This function copies the first n elements from the position defined by iterators first into the range starting by the iterator first2.
 */
void main2(){
    int values[] = {1,2,3,4,5,6,7,8,9};
    vector<int> v1(values, values+9), v2;

    copy_n(v1.begin(), 5, v2.begin()); // copies first 5 elements from v1 to v2.
    /* v2 is now 1,2,3,4,5 */
}
/*
 fill method

This method assigns the element a given value in the range defined by two iterators first and last. Syntax for fill() is, fill(iterator first, iterator last, int value).
 */
void main3(){
    vector<int> v(10); // v1 is now 0,0,0,0,0,0,0,0,0,0

    fill(v.begin(), v.end(), 5);
    /* now v1 is 5,5,5,5,5,5,5,5,5,5 */

    fill(v.begin(), v.end() - 5, 3);
    for(auto i:v){
        cout<<i<<" ";
    }
    /* now v11 is 3,3,3,3,3,5,5,5,5,5 */
}
/*
This method assingns the first n elements a given value from the position defined by iterator first. Syntax for fill_n is fill_n(iterator first, iterator last, int value)
 */
void main4(){
    int values[] = {1,2,3,4,5,6,7,8,9};
    vector<int> v1(values, values+9);

    fill_n(v1.begin()+3, 5 ,10);
    /* v1 is now 10,10,10,10,10,6,7,8,9 */
    for(auto i:v1){
        cout<<i<<" ";
    }
}
int main() {
    main4();
    return 0;
}