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
Following are some non-modifying algorithms in Standard Template library that we will be covering :

count
equal
mismatch
search
search_n
 */

/*
count
count() returns the number of elements in the given range that are equal to given value. Syntax for count is:

count(first ,last ,value) : This will return number of the element in range defined by iterators first and last ( excluded ) which are equal ( == ) the value .
 */
void main1(){
    int values[] = {5,1,6,9,10,1,12,5,5,5,1,8,9,7,46};

    int count_5 = count(values, values+15, 5);
    /* now count_5 is equal to 4 */
    cout<<count_5<<endl;
    vector<int> v(values, values+15);

    int count_1 = count(v.begin(), v.end(), 1);
    /* now count_1 is equal to  */
    cout<<count_1<<endl;
}

/*
equal
equal() compares the elements in two ranges, if all the elements in one range compares equal to their corresponding elements in other range, Boolean true is returned, else Boolean false is returned. There are two variation of it :

equal(first1, last1, first2) : This function compare for the equality of elements in the range pointed by first1 and last1(excluded) to the range with starting position first2. If all elements are equal , true is returned else false.
equal(first1 ,last1 ,first2 ,cmp_function) : Here cmp_function is used to decide how to check the equality of two elements, it is useful for non-numeric elements like strings and objects.
 */

void main2(){
    int inputs1[] = { 1,2,3,4,5,6,7,8};
    int inputs2[] = { -1,2,1,2,3,4,5,6,7,8,9};

    vector<int>  v1(inputs1 , inputs1+8);
    vector<int>  v2(inputs2 , inputs2+11);

    cout<<equal(v1.begin(), v1.end(), v2.begin()+2 ) ;  // prints 0 , boolean false

    /* use of compare function */
    string s1[] = { "abc" , "def" , "temp" , "testing" };
    string s2[] = { "xyz" , "emp" , "resr" , "testing" };

    cout<<equal( s1 , s1+4 , s2 , [](string i, string j)->bool{return i.size()==j.size();});   // prints 1
    /* note that the stings in s1 and s2 are not actually
    equal but still equal() returns 1 , beacause we are defining
    equality of two string by their length in cmp_function */
}
/*
 mismatch
This method returns a pair of iterator, where first iterator of the pair points to the element in first container and second iterator points to the element in the second container where mismatch has occurred. There are two variations of mismatch().

mismatch(first1, last1, first2) : Here first1 and last1 are the iterators to the first container specifying the range and first2 is the iterator to the second container specifying the position where to start the comparison. The elements are by default checked for equality == and the pair of iterator is returned giving the position of elements where mismatch has occurred.
mismatch(first1, last1, first2, compare_function) : This version works same as the above one except compare_function is used to check whether elements are to be consider equal or not.
 */
void main3(){
    int inputs1[] = {1,2,3,4,5,6,7,8};
    int inputs2[] = {1,2,1,2,3,4,6,7,8,9};

    vector<int> v1(inputs1 ,inputs1+9);
    vector<int> v2(inputs2 ,inputs2+9);

    pair<vector<int>::iterator, vector<int>::iterator>  position;
    /* defining a pair of iterator to the vector of integer */

    position = mismatch(v1.begin(), v1.end(), v2.begin()+2) ;
    cout<<*(position.first)<<endl;
    cout<<*(position.second)<<endl;
    /* now position.first is an iterator pointing
    to the 5th element in the vector v1 and position.second
    points to the 7th element in the vector v2 */

    /* use of compare function */
    string s1[] = {"abc", "def", "temp", "testing"};
    string s2[] = {"xyz", "emp", "res", "testing"};

    pair<string::iterator, string::iterator> position2;

    //position2 = mismatch( s1, s1+4, s2, [](string i, string j)->bool{return i.size()==j.size();});
    /* now position2.first is an iterator pointing
     to the 3rd element in s1 and position2.second points
     to the 3rd element in the s2 */
    cout<<"hello world!"<<endl;
}

/*
search
This function is used to perform searches for a given sequence in a given range. There are two variations of the search():

search(first1 ,last1 ,first2 ,last2) : This function searches for the sequence defined by first2 and last2 in the range first1 and last1(where last1 is excluded). If there is a match an iterator to the first element of the sequence in the range [first1,last1] is returned, else iterator to last1 is returned.
search(first1 ,last1 ,first2 ,last2 ,cmp_functions) : Here cmp_function is used to decide how to check the equality of two elements, it is useful for non-numeric elements like strings and objects.
 */
void main4(){
    int inputs1[] = { 1,2,3,4,5,6,7,8};
    int inputs2[] = { 2,3,4};

    vector<int> v1(inputs1, inputs1+9);
    vector<int> v2(inputs2, inputs2+3);

    vector<int>::iterator i ,j;

    i = search(v1.begin(), v1.end(), v2.begin(), v2.end());
    cout<<*i<<endl;
    /* now i points to the second element in v1 */

    j = search(v1.begin()+2, v1.end(), v2.begin(), v2.end());
    cout<<*j<<endl;
    /* j now points to the end of v1 as no sequence is equal to 2,3,4 in
    [v1.begin()+2 ,v1.end()] */
}

/*
 search_n
This method searches in a given range for a sequence of a count value. There are two variations of the search():

search(first1, last1, count, value) : This method searches for a sequence of count and value in the range defined by iterators first1 and last1(last1 is excluded). If there is a match an iterator to the first element of the sequence in the range [first1,last1] is returned, else iterator to last1 is returned.
search(first1, last1, count, value, cmp_functions) : Here cmp_function is used to decide how to check the equality of two elements, it is useful for non-numeric elements like strings and objects.
 */
void main5(){
    int inputs1[] = {1,2,3,4,4,4,8,5,6,7,8};

    vector<int> v1(inputs1, inputs1+11);
//    for(auto it:v1){
//        cout<<it<<endl;
//    }

    auto i = search_n(v1.begin(), v1.end(), 3, 4);

    /* now i points to the 4th  element in v1 */

    auto j = search_n(v1.begin(), v1.end(), 1, 8);
    cout<< *j <<endl;
    /* j now points to the end of v1 as no sequence is equal to 5,5 in
    [v1.begin()+2 ,v1.end() ). */
}
int main() {
    main5();
    return 0;
}
