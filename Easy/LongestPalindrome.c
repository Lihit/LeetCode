/*Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int cmp( const void *a , const void *b ) 
{ 
	return *(char *)a - *(char *)b; 
} 
int longestPalindrome(char* s) {
	int slen=strlen(s);
    if(slen==1) return 1;
    qsort(s,slen,sizeof(char),cmp);
    int flag=0;
    int ret=0;
    int count=1;
    for(int i=1;i<slen;i++){
    	if(s[i]==s[i-1]) count++;
    	else{
            if(i==slen-1) flag=1;
    		if(count%2){
    			flag=1;
    			ret+=(count-1);
    		}else{
    			ret+=count;
    		}
    		count=1;
    	}
    }
    if(count!=1) {
    	if(count%2) {ret+=(count-1);flag=1;}
    	else ret+=count;
    }
    return flag==1?ret+1:ret;
}
int main(int argc, char const *argv[])
{
	char s[]="aaaAaaaa";
	printf("%d\n",longestPalindrome(s));
	return 0;
}