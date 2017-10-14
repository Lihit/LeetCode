/*Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.*/

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
void deleteNode(struct ListNode* node) {
    if(node ==NULL) return;
    while(node->next->next!=NULL){
    	node->val=node->next->val;
    	node=node->next;
    }
    node->val=node->next->val;
    if(node->next){
    	free(node->next);
    	node->next=NULL;
    }
}
int main(int argc, char const *argv[])
{
	
	return 0;
}