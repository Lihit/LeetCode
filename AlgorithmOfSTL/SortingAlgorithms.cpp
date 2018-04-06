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
Sorting Algorithms in STL
We will be studying about three methods under Sorting Algorithms, namely :

sort
is_sorted
partial_sort
 */
bool compare_function(int i, int j)
{
    return i > j;    // return 1 if i>j else 0
}
bool compare_string(string i, string j)
{
    return (i.size() < j.size());
}

/*
sort
This function of the STL, sorts the contents of the given range.
 There are two version of sort() :
1.sort(start_iterator, end_iterator ) : sorts the range defined by iterators
 start_iterator and end_iterator in ascending order.
2.sort(start_iterator, end_iterator, compare_function) : this also sorts the
 given range but you can define how the sorting should be done by compare_function.
 */
void main1(){
    int arr[5] = {1,5,8,4,2};

    sort(arr , arr+5);    // sorts arr[0] to arr[4] in ascending order
    /* now the arr is 1,2,4,5,8  */

    vector<int> v1;

    v1.push_back(8);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(1);

    /* now the vector v1 is 8,4,5,1 */
    vector<int>::iterator i, j;

    i = v1.begin();   // i now points to beginning of the vector v1
    j = v1.end();     // j now points to end of the vector v1

    sort(i,j);      //sort(v1.begin() , v1.end() ) can also be used
    /* now the vector v1 is 1,4,5,8 */


    /* use of compare_function */
    int a2[] = { 4,3,6,5,6,8,4,3,6 };

    sort(a2,a2+9,compare_function);  // sorts a2 in descending order
    /* here we have used compare_function which uses operator(>),
    that result into sorting in descending order */

    /* compare_function is also used to sort non-numeric elements such as*/

    string s[]={"a" , "abc", "ab" , "abcde"};
    string sss = "hello";
    sort(s,s+4,compare_string);
    for_each(s,s+4,[&](string st){cout<<st+sss<<endl;});
    /* now s is "a","ab","abc","abcde"  */
}
/*
partial_sort
partial_sort() sorts first half elements in the given range,
 the other half elements remain as they was initially.
 partial_sort() also has two variations:
partial_sort(start, middle, end ) : sorts the range from start to end in such a way that the elements before middle are in ascending order and are the smallest elements in the range.
partial_sort(start, middle, end, compare_function) : sorts the range from start to end in such a way that the elements before middle are sorted with the help of compare_function and are the smallest elements in the range.
 */
template <typename T>
class compareClass{
public:
    bool operator()(T i, T j){
        return i>j;
    }
};
void main2(){
    int a[] = {9,8,7,6,5,4,3,2,1};

    partial_sort(a, a+4, a+9);
    /* now a is 1,2,3,4,9,8,7,6,5  */

    int b[] = {1,5,6,2,4,8,9,3,7};

    /* sorts b such that first 4 elements are the greatest elements
     in the array and are in descending order */
    partial_sort(b, b+4, b+9,compareClass<int>());
    /* now b is  9,8,7,6,1,2,4,3,5 */
    for_each(b,b+9,[](int i){cout<<i<<endl;});
}
/*
is_sorted
This function of the STL, returns true if the given range is sorted. There are two version of is_sorted() :

is_sorted(start_iterator, end_iterator) : Checks the range defined by iterators start_iterator and end_iterator in ascending order.
is_sorted(start_iterator, end_iterator, compare_function) : It also checks the given range but you can define how the sorting must be done.
 */

void main3(){
    int a[5] = {1,5,8,4,2};
    cout<<is_sorted(a, a+5);
    /* prints 0 , Boolean false  */

    vector<int> v1;

    v1.push_back(8);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(1);

    /* now the vector v1 is 8,4,5,1 */
    cout<<is_sorted(v1.begin() , v1.end() );
    /* prints 0 */
    sort(v1.begin() , v1.end() );
    /* sorts the vector v1 */
    cout<<is_sorted(v1.begin() , v1.end());
    /*  prints 1 , as vector v1 is sorted */
}
int main() {
    main3();
    return 0;
}