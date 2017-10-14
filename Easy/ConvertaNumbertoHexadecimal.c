/*Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
char* toHex(int num) {
	if(num==0) return "0";
	unsigned int tmp=num;
	char *ret=calloc(1,sizeof(char));
	memset(ret,0,sizeof(char));
	int count=0,mod=0;
	if(num<0) tmp=~abs(num)+1;
	while(tmp){
		ret=realloc(ret,(count+2)*sizeof(char));
		memmove(ret + 1, ret, (count + 1) * sizeof(char));
		mod=tmp%16;
		ret[0]=mod>9?mod-10+'a':mod+'0';
		tmp/=16;
		count++;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int num=-1;
	printf("%s\n",toHex(num));
	printf("%x\n",num);
	return 0;
}