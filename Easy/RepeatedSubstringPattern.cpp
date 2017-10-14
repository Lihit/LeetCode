/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
bool repeatedSubstringPattern(char* s) {
    int slen=strlen(s);
    for(int i=1;i<slen/2+1;i++){
    	int flag=0;
    	if(slen%i) continue;
    	else{
    		for(int j=0;j<slen/i-1;j++){
    			char tmp1=*(s+j*i);
    			char tmp2=*(s+(j+1)*i);
    			if(strncmp(s+j*i,s+(j+1)*i,i*sizeof(char))){
    				flag=1;
    				break;
    			}
    		}
    		if(flag==0) return true;
    	}
    }
    return false;
}
int main(int argc, char const *argv[])
{
	char s[]="a1a1a1a1a1a11";
	if(repeatedSubstringPattern(s)){
		printf("true\n");
	}
	return 0;
}