/*Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    while(*ransomNote++!='\0'){
    	char *tmp=strchr(magazine,*(ransomNote-1));
    	if(!tmp) return false;
    	else *tmp=' ';}
    return true;
}
int main(int argc, char const *argv[])
{
	char a[]="aa";
	char b[]="aab";
	if(canConstruct(a,b)){
		printf("find....\n");
	}
	return 0;
}