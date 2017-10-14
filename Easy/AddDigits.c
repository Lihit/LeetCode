/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int addDigits1(int num) {
	char *tmp=NULL;
	while(num/10){
		int num_tmp=0;
		int i=0;
		tmp=calloc(32,sizeof(int));
		sprintf(tmp,"%d",num);
		while(*(tmp+i)!='\0'){
			num_tmp+=(*(tmp+i)-'0');
			i++;
		}
		if(tmp!=NULL) free(tmp);
		num=num_tmp;
	}
	return num;
}
int addDigits2(int num) {
	while(num/10){
		int ret=0;
		while(num>0){
			ret+=num%10;
			num/=10;
		}
		num=ret;
	}
	return num;
}

int addDigits(int num) {
   int s;
   return  (s=num %9)?s:(num?9:0);
}
int main(int argc, char const *argv[])
{
	printf("%d\n",addDigits(18));
	return 0;
}