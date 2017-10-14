/*Given an integer array with even length, where different numbers in this array represent different 
kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these 
candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int distributeCandies(int* candies, int candiesSize) {
	int ret=0;
	if(candies==NULL){
		ret=-1;
		return ret;
	}
	ret=candiesSize/2;
	int count=0;
	int candyTmp[200001]={0};
	int i=0;
	for(i=0;i<candiesSize;i++){
		if(candyTmp[candies[i]+100000]!=1){
			count++;
		}
		candyTmp[candies[i]+100000]=1;
	}
	if(count<ret){
		ret=count;
	}

    return ret;
}

int main(int argc, char const *argv[])
{
	int candies[]={1,1,2,3};
	int ret=distributeCandies(candies,4);
	printf("%d\n",ret);
	return 0;
}