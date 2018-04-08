//
// Created by wenshao on 2018/4/8.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <utility>
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
move
This method moves the elements form the current container and return its rvalue reference. Syntax for move is move(element). move() is available in C++ 11 and above.
 */
void main1(){
    string a = "nicky";
    string b = "vicky";
    vector<string> name;

    // inserts "nicky" in name , a is still = nicky
    name.push_back(a);
    cout<<a<<endl;
    // inserts "Vicky" in name , b is now NULL
    name.push_back(move(b));
    cout<<b<<endl;
}
/*
transform
transform applies a unary/binary operation on a given range and copies the result into the range starting from iterator res. There are two version of transform() which differ by the type of operations performed on the elements.

transform(iterator first1, iterator last1, iterator res, unaryoperation op) : This method performs unary operation op on the elements in range [first1,last1] and stores the result in range starting from res.
transform(iterator first1, iterator last1, iterator first2, iterator res, unaryoperation op) : This method performs binary operation op on the elements in range [first1,last1] with the elements in the range starting with iterator first2 and stores the result in range starting from res.
 */
int unaryoperation (int a,int b,int c)
{
    return a+b*c;
}
void main2(){
    vector<int> v1;
    vector<int> v2;
    vector<int> res1;
    vector<int> res2;

    for(int i=0; i < 10; i++)
    {
        v2.push_back(i);
        v1.push_back(i*10);
    }

    /*   v2 :  1,2,3,4,5,6,7,8,9  */
    /*   v1 :  10,20,30,40,50,60,70,80,90  */

    res2.resize(10);

    transform(v2.begin(), v2.end(), v1.begin(), res2.begin(), bind(unaryoperation,std::placeholders::_1,std::placeholders::_2,122));
    /* now res1 is : 2,4,6,8,10,12,14,16,18 */
    for(auto i : res2){
        cout<<i<<endl;
    }
}
bool check_size(const int x,int sz)
{
    return x > sz;
}

/*
generate and generate_n
generate method

This method assigns all the elements in the given range to the value returned by the successive call to function generate_element. Syntax for generate is generate(iterator first, iterator last, generator_function generate_element).


generate_n method

This method assigns first n elements in the given range to the value returned by the successive call to function generate_element. Syntax for generate is generate(iterator first, int n, generator_function generate_element).
 */

int generate_random()
{
    return rand()%10;
}
void main3(){
    srand((unsigned)time(0));
    vector<int> v1 , v2;
    v1.resize(10);
    v2.resize(10);
    generate(v1.begin(), v1.end(), generate_random) ;
    for(auto i : v1){
        cout<<i<<" ";
    }
    cout<<endl;
    /* this assign each element a random value generated
    by the generate_random() */

    generate_n(v2.begin(), 12, generate_random);
    for(auto i : v2){
        cout<<i<<" ";
    }
    /* this assign first 5 elements a random value
    and rest of the elements are un changed */
}
/*
swap Method
This method swaps the elements of two container of same type.
 */
void main4(){
    int a = 6;
    int b = 9;

    swap(a,b);
    /* a = 9 , b=6 */
    cout<<a<<b<<endl;
    /* you can also swap an entire container with swap */
    int qq[]={1,2,3,4,5};
    swap(qq[1],qq[4]);
    for_each(qq,qq+5,[](int i){cout<<i<<endl;});
    vector<int> v, c;
    for(int j=0; j < 10; j++)
    {
        v.push_back(j);
        c.push_back(j+1);
    }

    swap(v,c);
}
/*
swap_ranges
swap_ranges(iterator first1, iterato last1, iterato first2) : It swaps the elements in the range [first1, last1] with the elements present in the range starting from first2.
 */
void main5(){
    vector<int> v, c;
    for(int j=0; j < 10; j++)
    {
        v.push_back(j);
        c.push_back(j+1);
    }

    swap_ranges(v.begin(), v.begin()+5, c.begin());

    /* swaps the first five element of
    vector v by the elements of vector c */

    for(vector<int>::iterator i = v.begin() ; i!= v.end() ; i++)
        cout<< *i <<" ";

    cout<<endl;

    for(vector<int>::iterator k = c.begin() ; k!= c.end() ; k++)
        cout<<*k<<" ";
}
int main() {
    main5();
    return 0;
}