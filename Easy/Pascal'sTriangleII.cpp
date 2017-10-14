/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize=rowIndex+1;
    int *ret=(int *)calloc(*returnSize,sizeof(int));
    int tmp=0,tmp1=0;
    for(int i=1;i<*returnSize;i++){
    	ret[0]=ret[i]=1;
    	tmp=ret[0];
    	for(int j=1;j<i;j++){
    		tmp1=tmp+ret[j];
    		tmp=ret[j];
    		ret[j]=tmp1;
    	}    	
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	int returnSize=0;
	int *ret=getRow(5,&returnSize);
	for(int i=0;i<returnSize;i++){
		printf("%d\n", ret[i]);
	}
	return 0;
}