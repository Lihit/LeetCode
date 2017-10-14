/*You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
bool checkRecord(char* s) {
	char *stmp=strchr(s,'A');
    if(stmp && strchr(stmp+1,'A')) return false;
    else if(strstr(s,"LLL")) return false;
    else return true;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}