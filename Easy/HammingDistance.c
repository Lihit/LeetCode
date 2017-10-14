/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ?   ?

The above arrows point to positions where the corresponding bits are different.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int hammingDistance(int x, int y) {
	int ret=0;
	int x_mod=0;
	int y_mod=0;
	if(x<0|| y<0||x>pow(2,31)||y>pow(2,31)){
		ret=-1;
		return ret;
	}
	while(x || y){
		int x_tmp=x/2;
		int y_tmp=y/2;
		x_mod=x-x_tmp*2;
		y_mod=y-y_tmp*2;
		if(x_mod!=y_mod){
			ret++;
		}
		x=x_tmp;
		y=y_tmp;
	}
    return ret;
}

int main(){
	int x=4;
	int y=4;
	printf("%d\n", hammingDistance(x,y));
	return 0;
}
