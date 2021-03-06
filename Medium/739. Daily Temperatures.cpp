//
// Created by wenshao on 2017/12/7.
//

/*
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(),0);
        stack<pair<int,int>> mys;
        for(int i=0;i<temperatures.size();i++){
            while(!mys.empty()){
                pair<int,int> pt=mys.top();
                if(temperatures[i]>pt.second){
                    ret[pt.first]=i-pt.first;
                    mys.pop();
                }else{
                    break;
                }
            }
            pair<int,int> np(i,temperatures[i]);
            mys.push(np);
        }
        return ret;
    }
};

int main() {
    return 0;
}