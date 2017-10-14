/*There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.

Answer this question, and write an algorithm for the follow-up general case.

Follow-up:

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs=0;
    while(pow(minutesToTest/minutesToDie+1,pigs)<buckets) pigs++;
    return pigs;
}
int main(int argc, char const *argv[])
{
	printf("%d\n", poorPigs(1000,15,60));
	return 0;
}