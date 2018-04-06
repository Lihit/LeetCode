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
binary_search
This function returns Boolean true if the element is present in the given range, else Boolean false is returned. There are two variations of binary_search():

binary_search(first, last, value) : this version returns true if there is an element present, satisfying the condition (!(a < value) &&!(value < a)) in the given range, i.e from first to last, in other words, operator(<) is used to check the equality of the two elements.
binary_search(first, last, value, compare_function) : this version return true if there is an element present in the given range, i.e from first to the last.
Note that first and last are iterators and the element pointed by last is excluded from the search.

Here we don't have to first sort element container, binary_search() will do all the work for us, we just have to give a range and a value which is to searched.
 */

bool compare_string_by_length (string i,string j)
{
    return (i.size() == j.size());
}

void main1(){
    int inputs[] = {7,8,4,1,6,5,9,4};
    sort(inputs,inputs+8);
    vector<int> v(inputs, inputs+8);

    cout<<binary_search(v.begin() , v.end() , 7 );  //prints 1 , Boolean true

    cout<<binary_search(v.begin() , v.end() , 217); //prints 0 , Boolean false

    /* compare_function can be used to search
    non numeric elements based on their properties */

    string s[] = {  "test" ,"test1" , "abcdf" , "efghijkl"};
    cout<<s->size()<<endl;
    cout<<binary_search(s,s+4,"test",compare_string_by_length);
    /* search for the string in s which have same length as of "nicky" */
}
/*
equal_range
equal_range() returns a pair of iterators where the iterators represent the sub range of elements in the given range which are equal to the given value or satisfy the compare_function. The given range should be already sorted. There are two variation of equal_range :

equal_range(first, last, value) : returns a pair of iterators representing the sub range of (first,last) which have elements equal to value.
equal_range(first, last, value, compare_function) : returns a pair of iterators representing the sub range of (first,last) which have elements satisfying compare_function with value.
 */
bool compare_function (int i,int j) { return (i <= j); }
void main2(){
    int input[] = {1,1,1,2,2,2,3,3,6,7,7,7,7,7,8,9};
    vector<int> v(input, input+16);

    pair< vector<int>::iterator, vector<int>::iterator > sub_range;
    /* defining the pair of two iterators to an integer vector */


    sub_range = equal_range (v.begin(), v.end(), 2);
    /* now sub_range.first points to 4th element in the vector v and
      sub_range.second points to 7th element ,
      note that sub_range.secong points to the element
      which is next to the element in the subrange  */

    sub_range = equal_range (v.begin(), v.end(), 20, compare_function);
    /* sub_range.first points to first element in the vector v ,
    as it satisfy the condition exerted by compare_function , <= ,
      sub_range.second points to 7th element in the vector . */
    for_each(sub_range.first,sub_range.second,[](int i){cout<<i<<endl;});
}
int main() {
    main2();
    return 0;
}