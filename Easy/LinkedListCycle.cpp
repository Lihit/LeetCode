/*Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

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

bool hasCycle1(struct ListNode *head) {
    if(head==NULL) return false;
    char *tmp=(char*)calloc(10,sizeof(char));
    sprintf(tmp,"%d,",head);
    int count=1;
    while(head->next){
    	count++;
    	head=head->next;
    	char *tmp1=(char*)calloc(10,sizeof(char));
    	sprintf(tmp1,"%d,",head);
    	if(strstr(tmp,tmp1)){
    		return true;
    	}else{
    		tmp=(char*)realloc(tmp,(count*10)*sizeof(char));
    		strcat(tmp,tmp1);
    	}
    }
    return false;
}
bool hasCycle(struct ListNode *head) {
    
    struct ListNode *ptr1=head, *ptr2=head;
    
    while(ptr2!=NULL && ptr2->next!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
        if(ptr1==ptr2)
            return true;
    }
    return false;
    
}
int main(int argc, char const *argv[])
{
	struct ListNode root;
	root.val=1;
	root.next=&root;
	if(hasCycle(&root)){
		printf("hello...\n");
	}
	return 0;
}