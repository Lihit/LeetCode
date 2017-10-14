/*You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int islandPerimeter(int **grid, int gridRowSize, int gridColSize) {
    int ret=0;
    int i=0;
    int j=0;
    for(i=0;i<gridRowSize;i++){
    	if(i==0){
    		for(j=0;j<gridColSize;j++){
    			if(grid[i][j]==1){
    				ret++;
    			}
    		}
    	}
    	else{
    		for(j=0;j<gridColSize;j++){
    			if((grid[i][j]==0 &&grid[i-1][j]==1)|| (grid[i][j]==1 &&grid[i-1][j]==0)){
    				ret++;
    			}
    		}
    	}
    	if(i==gridRowSize-1){
    		for(j=0;j<gridColSize;j++){
    			if(grid[i][j]==1){
    				ret++;
    			}
    		}
    	}
    }

    for(i=0;i<gridColSize;i++){
    	if(i==0){
    		for(j=0;j<gridRowSize;j++){
    			if(grid[j][i]==1){
    				ret++;
    			}
    		}
    	}
    	else{
    		for(j=0;j<gridRowSize;j++){
    			if((grid[j][i]==0 &&grid[j][i-1]==1)|| (grid[j][i]==1 &&grid[j][i-1]==0)){
    				ret++;
    			}
    		}
    	}
    	if(i==gridColSize-1){
    		for(j=0;j<gridRowSize;j++){
    			if(grid[j][i]==1){
    				ret++;
    			}
    		}
    	}
    }

    return ret;
}


int main(int argc, char const *argv[])
{
	int a[4][4]={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};

	int ret=islandPerimeter(a,4,4);

	printf("%d\n", ret);
	return 0;
}