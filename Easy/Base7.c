/*Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
char* convertToBase7(int num) {
	char *ret=calloc(10,sizeof(char));
    if(num==0) return "0";
    else if(num>0){
        char *tmp=convertToBase7(num/7);
        sprintf(ret,"%s%d",tmp=="0"?"":tmp,num%7,0);
    } 
    else sprintf(ret,"-%s",convertToBase7(abs(num)));
    return ret;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}