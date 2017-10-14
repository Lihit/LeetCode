/*Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings.
 The longest uncommon subsequence is defined as the longest subsequence of one of these strings and 
 this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without
 changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an
  empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence.
 If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"), 
because "aba" is a subsequence of "aba", 
but not a subsequence of any other strings in the group of two strings. 
Note:

Both strings' lengths will not exceed 100.
Only letters from a ~ z will appear in input strings.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int getmax(int *array,int size){
	int max=0;
	int i=0;
	for(i=0;i<size;i++){
		if(*(array+i)>max){
			max=*(array+i);
		}
	}
	return max;
}
int findLUSlength1(char* a, char* b) {
	int ret=0;
	int i=0;
	int size=0;
	int count=0;
    int a_len=strlen(a);
    int b_len=strlen(b);
    int *tmp=NULL;
    if(a_len!=b_len){
    	return a_len>b_len?a_len:b_len;
    }
    for(i=0;i<a_len;i++){
    	if(*(a+i)!=*(b+i)){
    		count++;
    	}else{
    		if(count!=0){
    			tmp=realloc(tmp,(size+1)*sizeof(int));
    			tmp[size]=count;
    			count=0;
    			size++;
    		}
    	}
    }
    ret=getmax(tmp,size);
    return ret>0?ret:-1;
}

int findLUSlength(char* a, char* b) {
	int ret=0;
	int i=0;
	int count=0;
    int a_len=strlen(a);
    int b_len=strlen(b);
    if(a_len!=b_len){
    	return a_len>b_len?a_len:b_len;
    }else{
    	if(strcmp(a,b)!=0) ret=a_len;
    	else ret=-1;
    	return ret;
    }
}
int main(int argc, char const *argv[])
{
	char a[]="aaa";
	char b[]="bba";
	printf("%d\n", findLUSlength(a,b));
	return 0;
}