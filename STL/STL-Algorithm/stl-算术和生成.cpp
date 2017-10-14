#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;


void printV(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


//累加
void main1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    int tmp = accumulate(v1.begin(), v1.end(), 100);
    cout << tmp << endl;
}

//填充
void main2(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    fill(v1.begin(),v1.end(),100);
    printV(v1);   
}
int main(int argc, char const *argv[])
{
    main2();
    return 0;
}