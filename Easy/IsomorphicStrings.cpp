/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>


bool isIsomorphic(char* s, char* t) {
    int tmp[256]={0};
    int tmp1[256]={0};
    while(*s!='\0'){
    	int index1=*s-'\0',index2=*t-'\0';
    	if(tmp[index1]==0){
    		if(tmp1[index2]!=0) return false;
    		else{
    			tmp[index1]=index2;
    			tmp1[index2]++;
    		}
    	}
    	else{
    		if(tmp[index1]!=index2) return false;
    	}
    	s++;
    	t++;	
    }
    return true;
}

int main(int argc, char const *argv[])
{
	char s[]="foo";
	char t[]="bar";
	if(!isIsomorphic(s,t)) printf("hello...\n");
	return 0;
}