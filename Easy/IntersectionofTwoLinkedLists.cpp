

/*Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int Alen = 0, Blen = 0;
        ListNode *tmpA = headA, *tmpB = headB;
        while (tmpA || tmpB) {
            if (tmpA) {
                Alen++;
                tmpA = tmpA->next;
            }
            if (tmpB) {
                Blen++;
                tmpB = tmpB->next;
            }
        }
        int sub = abs(Alen - Blen);
        if (sub == 0) {
            if (headA == headB) return headA;
            else return NULL;
        }
        for (int i = 0; i < sub; i++) {
            if (Alen > Blen) {
                headA = headA->next;
            }
            else {
                headB = headB->next;
            }
        }
        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
int main(int argc, char const *argv[])
{
    ListNode l1, l2, l3, l4, l5;
    l1.val = 1;
    l2.val = 1;
    l3.val = 1;
    l4.val = 1;
    l5.val = 1;

    return 0;
}