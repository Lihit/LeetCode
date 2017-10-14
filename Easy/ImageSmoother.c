/*Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
    int **ret=(int **)malloc(MRowSize*sizeof(int*));
    *columnSizes=calloc(MRowSize,sizeof(int));
    for(int i=0;i<MRowSize;i++){
    	ret[i]=calloc(MColSize,sizeof(int));
    	(*columnSizes)[i]=MColSize;
    	for(int j=0;j<MColSize;j++){
    		int sum=M[i][j];
    		int count=1;
    		for(int k=0;k<8;k++){
    			switch(k){
    				case 0:
    					if(j-1>=0) {sum+=M[i][j-1];count++;}
    					break;
    				case 1:
    					if(i-1>=0&&j-1>=0) {sum+=M[i-1][j-1];count++;}
    					break;
    				case 2:
    					if(i-1>=0) {sum+=M[i-1][j];count++;}
    					break;
    				case 3:
    					if(i-1>=0&&j+1<MColSize) {sum+=M[i-1][j+1];count++;}
    					break;
    				case 4:
    					if(j+1<MColSize) {sum+=M[i][j+1];count++;}
    					break;
    				case 5:
    					if(i+1<MRowSize&&j+1<MColSize) {sum+=M[i+1][j+1];count++;}
    					break;
    				case 6:
    					if(i+1<MRowSize) {sum+=M[i+1][j];count++;}
    					break;
    				case 7:
    					if(i+1<MRowSize&&j-1>=0) {sum+=M[i+1][j-1];count++;}
    					break;
    			}
    		}
    		ret[i][j]=floor(1.0*sum/count);
    	}	
    }
    * returnSize=MRowSize;
    return ret;
}

int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
    int **ret=(int **)malloc(MRowSize*sizeof(int*));
    *columnSizes=calloc(MRowSize,sizeof(int));
    for(int i=0;i<MRowSize;i++){
        ret[i]=calloc(MColSize,sizeof(int));
        (*columnSizes)[i]=MColSize;
        for(int j=0;j<MColSize;j++){
            int sum=0,count=0;
            int xmin=fmax(i-1,0),xmax=fmin(i+1,MRowSize-1);
            int ymin=fmax(j-1,0),ymax=fmin(j+1,MColSize-1);
            for(int x=xmin;x<=xmax;x++){
                for(int y=ymin;y<=ymax;y++){
                    sum+=M[x][y];
                    count++;
                }
            }
            ret[i][j]=floor(1.0*sum/count);
        }   
    }
    * returnSize=MRowSize;
    return ret;
}
int main(int argc, char const *argv[])
{
	printf("%d\n",(int)floor(1.0*16/4) );
	return 0;
}
