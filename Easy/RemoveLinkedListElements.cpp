/*Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        ListNode* preNode = head;
        ListNode* currentNode = head->next;
        while (currentNode) {
            if (currentNode->val == val) {
                ListNode *tmp = currentNode->next;
                preNode->next = tmp;
                currentNode = tmp;
            }
            else {
                currentNode = currentNode->next;
                preNode = preNode->next;
            }
        }
        return head->val == val ? head->next : head;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    ListNode root;
    root.val = 2;
    root.next = NULL;
    ListNode *ret = s.removeElements(&root, 1);
    while (ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}