/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

bool isValid(const char* s) {
	int i = 0, j = strlen(s) - 1;
	if ((j + 1) % 2) return false;
	char left[]="({[";
	char right[]=")}]";
	while (i < j) {
		int tmp = *(s + i) + *(s + j);
		if (tmp != 81 && tmp != 184 && tmp != 248) return false;
		i++;
		j--;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	printf("%d\n", isValid("()[]{}"));
	return 0;
}