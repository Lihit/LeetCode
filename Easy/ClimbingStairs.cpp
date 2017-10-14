/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int factorial(int m,int n=0){
	if(m==1 || m==n+1) return m;
	else return m*factorial(m-1,n);
}
int comb(int m,int n){
	if(m==n||n==0) return 1;
	else return factorial(m,n)/factorial(m-n);
}
unsigned int climbStairs1(int n) {
    int tmp=n/2;
    unsigned int ret=0;
    for(int i=tmp;i>=0;i--){
    	ret+=comb(n-i,i);
    }
    return ret;
}

int climbStairs(int n) {
	//int *ret=(int *)malloc(n*sizeof(int));
	int *ret=(int *)calloc(n,sizeof(int));
    for(int i=1;i<=n;i++){
    	if(i==1||i==2) ret[i-1]=i;
    	else ret[i-1]=ret[i-2]+ret[i-3];
    }
    ret=(int *)realloc(ret,n+1);
    ret[n]=100;
    return ret[n-1];
}


int main(int argc, char const *argv[])
{
	int tmp[10]={10};
	int n=4;
	
	int ret1=climbStairs(n);
	int ret2=climbStairs(n+1);
	int ret3=climbStairs(n+2);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);
	return 0;
}
