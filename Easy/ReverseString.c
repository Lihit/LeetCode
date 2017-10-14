/*Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* reverseString(char* s) {
    int low=0;
    int high=strlen(s)-1;
    while(low<high){
    	char tmp=*(s+low);
    	*(s+low)=*(s+high);
    	*(s+high)=tmp;
    	low++;
    	high--;
    }
    return s;
}
int main(int argc, char const *argv[])
{
	char s[]="shdsuishd";
	printf("%s\n", reverseString(s));
	return 0;
}