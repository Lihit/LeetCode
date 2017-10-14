/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

char* reverseVowels(char* s) {
    int i=0,j=strlen(s)-1;
    char *tmp="aeiouAEIOU";
    while(i<j){
    	char *t1=strchr(tmp,*(s+i));
    	char *t2=strchr(tmp,*(s+j));
    	if(t1 && t2){
    		char t=*(s+i);
    		*(s+i++)=*(s+j);
    		*(s+j--)=t;
    	}
    	else if(t1 && !t2) j--;
    	else if(!t1 && t2) i++;
    	else{
    		i++;
    		j--;
    	}
    }
    return s;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}