#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <pthread.h> 
#include <math.h>

void pattern1(int size, int a){
	unsigned long long ret=0,n=size/(2*a);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a;j++){
			unsigned long long tmp=1;
			ret^=(tmp<<(2*a*i-j));
		}
	}
	//18446744073709551615
	printf("%llx\n", ret);
}

void pattern(int size, int a){
	int *ret=(int *)calloc(size,sizeof(int));
	int n=size/(2*a);
	memset(ret,0,sizeof(int)*size);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a;j++){
			ret[2*a*i-j]=1;
		}
	}
	for (int i = size-1; i >=0; i--)
	{
		printf("%d", ret[i]);
	}
	
}

int main(int argc, char const *argv[])
{
	pattern(256,2);
	//printf("%d\n",sizeof(unsigned long long int));
/*	double ret=pow(2,3);
	printf("%f\n", ret);
	unsigned long tmp=(int)ret;
	printf("%d\n", tmp);
	printf("%f\n", pownew(32));*/
	return 0;
}