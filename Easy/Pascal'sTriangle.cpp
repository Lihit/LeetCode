/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int** generate(int numRows, int** columnSizes) {
    int **ret=(int **)malloc(numRows*sizeof(int *));
    *columnSizes=(int *)calloc(numRows,sizeof(int));
    for(int i=0;i<numRows;i++){
    	(*columnSizes)[i]=i+1;
    	ret[i]=(int *)calloc(i+1,sizeof(int));
    	ret[i][0]=ret[i][i]=1;
    	if(i>1){
    		for(int j=1;j<i;j++){
    			ret[i][j]=ret[i-1][j]+ret[i-1][j-1];
    		}
    	}
    }
    return ret;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}
