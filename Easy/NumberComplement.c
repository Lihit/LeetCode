/*Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int findComplement(int num) {
	int num_mod=0;
	int num_tmp=0;
	int ret=0;
	int count=0;
	while(num){
		num_tmp=num/2;
		num_mod=num-num_tmp*2;
		ret+=pow(2,count)*(num_mod>0?0:1);
		count++;
		num=num_tmp;
	}
    return ret;
}

int main(int argc, char const *argv[])
{
	int ret=findComplement(1);
	printf("%d\n", ret);
	return 0;
}