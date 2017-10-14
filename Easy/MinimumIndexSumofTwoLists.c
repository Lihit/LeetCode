/*Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
	char **ret=(char**)malloc((list1Size<list2Size?list1Size:list2Size)*sizeof(char*));
	int count=0;
	int minSum=0;
	for(int i=0;i<list1Size;i++){
		for(int j=0;j<list2Size;j++){
			if(!strcmp(list1[i],list2[j])){
				if((count==0&&minSum==0)||i+j==minSum){
					ret[count]=(char*)malloc((strlen(list1[i])+1)*sizeof(char));
					strcpy(ret[count],list1[i]);
					count++;
					minSum=i+j;
					break;					
				}
				else if(i+j<minSum){
					count=0;
					minSum=i+j;
					ret[count]=(char*)malloc((strlen(list1[i])+1)*sizeof(char));
					strcpy(ret[count],list1[i]);	
					count++;				
				}

			}
		}
	}
	* returnSize=count;
	return ret;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}