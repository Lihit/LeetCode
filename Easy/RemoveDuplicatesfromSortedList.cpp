/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL) return NULL;
    struct ListNode* preNode=head;
    struct ListNode* currentNode=head->next;
    while(currentNode){
    	if(preNode->val==currentNode->val){
    		struct ListNode* tmp=currentNode->next;
    		preNode->next=tmp;
    		currentNode=tmp;
    	}else{
            preNode=currentNode;
            currentNode=currentNode->next;
        }
    }
    return head;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}