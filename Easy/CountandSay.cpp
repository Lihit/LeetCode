/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"*/

#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h> 

char* countAndSay(int n) {
    char *ret=(char *)calloc(2,sizeof(char));
    ret[0]='1';
    ret[1]='\0';
    int i=0,j=0,k=0;
    for(i=0;i<n-1;i++){
    	for(j=0;ret[j]!='\0';){
    		for(k=j+1;ret[k]!='\0';k++){
    			if(ret[j]!=ret[k]) break;
    		}
    		int tmp=k-j;
    		int slen=strlen(ret);
    		if(tmp==1){
    			ret=(char*)realloc(ret,(slen+2)*sizeof(char));
    			memmove(ret+k+1,ret+k,(slen-k+1)*sizeof(char));
    		}else{
    			memmove(ret+j+2,ret+k,(slen-k+1)*sizeof(char));
    		}
    		ret[j+1]=ret[j];
    		ret[j]=tmp+'0';
    		j=j+2;  		
    	}
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	printf("%s\n", countAndSay(10));
	return 0;
}

/* 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.   13211311123113112211*/