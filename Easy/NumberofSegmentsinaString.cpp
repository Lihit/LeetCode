/*Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int countSegments(char* s) {
    int ret=0;
    int slen=strlen(s);
    for(int i=0;i<slen;i++){
    	if(*(s+i)!=' ' && (*(s+i+1)=='\0' || *(s+i+1)==' ')){
    		ret++;
    	}
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	char s[]=" dddsa  daf as";
	int ret=countSegments(s);
	printf("%d\n", ret);
	return 0;
}