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
struct ListNode* reverseList1(struct ListNode* head) {
    if(head==NULL) return NULL;
    int *arrraytmp=NULL;
    struct ListNode* tmp=head->next;
    int count=0;
    while(tmp){
    	arrraytmp=realloc(arrraytmp,(++count)*sizeof(int));
    	arrraytmp[count-1]=tmp->val;
    	tmp=tmp->next;
    }
    struct ListNode* tmp2=head->next;
    for(int i=count-1;i>=0;i--){
    	tmp2->val=arrraytmp[i];
        tmp2=tmp2->next;
    }
    return head;
}
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) return NULL;
	struct ListNode* preNode = head;
	struct ListNode* currentNode = head->next;
	if (currentNode == NULL) return head;
	preNode->next = NULL;
	while (currentNode) {
		if (currentNode->next == NULL) {
			currentNode->next = preNode;
			break;
		}
		struct ListNode* tmp = currentNode->next;
		currentNode->next = preNode;
		preNode = currentNode;
		currentNode = tmp;
	}
	return currentNode;
}
int main(int argc, char const *argv[])
{
	struct ListNode head,l1,l2,l3;
	l1.val=1;
	l2.val=2;
	l3.val=43;
	head.next=&l1;
	l1.next=&l2;
	l2.next=NULL;
	l3.next=NULL;
	struct ListNode*ret=reverseList(&l1);
	while(ret->next){
		printf("%d\n", ret->next->val);
		ret=ret->next;
	}
	return 0;
}