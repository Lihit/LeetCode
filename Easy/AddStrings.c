/*Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
char* addStrings(char* num1, char* num2) {
	int count = 0;
	int carry = 0;
	int add = 0;
	char *ret = calloc(1,sizeof(char));
	memset(ret,0,sizeof(char));
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	if (len1 >= len2) {
		for (int i = len1 - 1;i >= 0;i--) {
			ret = realloc(ret, (count + 2) * sizeof(char));
			memmove(ret + 1, ret, (count + 1) * sizeof(char));
			if (count<len2) {
				add = (num1[i] - '0' + num2[len2 - 1 - count] - '0') + carry;
				carry = add / 10;
				ret[0] = add - 10 * carry + '0';
				count++;
			}
			else {
				add = num1[i] - '0' + carry;
				carry = add / 10;
				ret[0] = add - 10 * carry + '0';
				count++;
			}
		}
		if (carry != 0) {
			ret = realloc(ret, (count + 2) * sizeof(char));
			memmove(ret + 1, ret, (count + 1) * sizeof(char));
			ret[0] = carry + '0';
		}
		return ret;
	}
	else {
		return addStrings(num2, num1);
	}
}
int main(int argc, char const *argv[])
{
	char *s=NULL;
	printf("%s\n", addStrings("999999","191"));
	return 0;
}