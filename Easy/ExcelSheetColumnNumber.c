/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int titleToNumber(char* s) {
    double ret=0;
    int slen=strlen(s);
    while(*s++) ret+=pow(26,--slen)*(*(s-1)-'A'+1);
    return (int)ret;
}
int main(int argc, char const *argv[])
{
	printf("%d\n",titleToNumber("BA"));
	return 0;
}