/*Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int cmp( const void *a , const void *b ) 
{ 
	return *(char *)a - *(char *)b; 
} 
bool isAnagram(char* s, char* t) {
	int slen=strlen(s);
	int tlen=strlen(t);
    if(slen!=tlen) return false;
    qsort(s,slen,sizeof(char),cmp);
    qsort(t,tlen,sizeof(char),cmp);
    return !strcmp(s,t);
}
int main(int argc, char const *argv[])
{
	
	return 0;
}