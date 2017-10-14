/*Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* reverseWords(char* s) {
	if(s==NULL){
		return NULL;
	}
	char *wordsReturn=NULL;
	int slen=strlen(s);
	wordsReturn=(char*)malloc(sizeof(char)*(slen+1));
	int space1=0;
	int space2=0;
	int i=0;
	int j=0;
	for(i=0;i<=slen;i++){
		if(*(s+i)==' ' || *(s+i)=='\0'){
			space1=space2;
			space2=i;
			for(j=space1;j<space2;j++){
				*(wordsReturn+j)=*(s+space2-1-j+space1);
			}
			*(wordsReturn+space2)=' ';
			space2++;

		}
	}
 	*(wordsReturn + slen) = '\0';
    return wordsReturn;
}

int main(int argc, char const *argv[])
{
	char *s="Let'stake Leet Code contest";
	char * ret=reverseWords(s);
	if(ret!=NULL){
		printf("%s\n",ret);
	}
	
	return 0;
}