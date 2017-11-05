/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *preNode = newHead;
        while (preNode) {
            if (preNode->next == NULL || preNode->next->next == NULL) break;
            ListNode *tmp = preNode->next->next;
            preNode->next->next = tmp->next;
            tmp->next = preNode->next;
            preNode->next = tmp;
            preNode = preNode->next->next;
        }
        return newHead->next;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}