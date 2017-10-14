/*Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getP(int n){
    int ret=1;
    if(n==0){
        return 0;
    }
    else{
        return ret+getP(n/10);
    }
}
char** fizzBuzz(int n, int* returnSize) {
    int i=0;
    char **ArrayReturn=NULL;
    ArrayReturn=(char **)malloc(sizeof(char*)*n);
    for(i=1;i<=n;i++){
        if(i%3==0&&i%5==0){
            ArrayReturn[i-1]=(char*)malloc(sizeof(char)*9);
            ArrayReturn[i-1]="FizzBuzz";
        }
        else if(i%3==0){
            ArrayReturn[i-1]=(char*)malloc(sizeof(char)*5);
            ArrayReturn[i-1]="Fizz";
        }
        else if(i%5==0){
            ArrayReturn[i-1]=(char*)malloc(sizeof(char)*5);
            ArrayReturn[i-1]="Buzz";
        }
        else{
            int ret=getP(i);
            ArrayReturn[i-1]=(char*)malloc(sizeof(char)*(ret+1));
            sprintf(ArrayReturn[i-1],"%d\0",i);
            //strcat(ArrayReturn[i-1],"\0");
        }

    }
    *returnSize=n;
    return ArrayReturn;
}

int main(int argc, char const *argv[])
{
    //int ret=getP(145);
    int returnSize=0;
    char **ArrayReturn=fizzBuzz(1,&returnSize);
    for(int i=0;i<returnSize;i++){
        printf("%s\n", ArrayReturn[i]);
    }
    //printf("%d\n",ret );


    return 0;
}