// Given a singly linked list, determine if it is a palindrome.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int i=0,j=v.size()-1;
        while(i<j){
            if(v[i]!=v[j]) return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}