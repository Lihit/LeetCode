/*Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool judgeCircle(char* moves) {
	int ret[2]={0};
	while(*moves++){
		switch(*(moves-1)){
			case 'U':ret[0]+=1;
			break;
			case 'D':ret[0]-=1;
			break;
			case 'L':ret[1]+=1;
			break;
			case 'R':ret[1]-=1;
			break;
		}
	}
	return ret[0]==0&&ret[1]==0;
}
int main(int argc, char const *argv[])
{
	printf("%d\n", judgeCircle("LR"));
	return 0;
}