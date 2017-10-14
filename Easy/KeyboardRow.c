/*Given a List of words, return the words that can be typed using letters of alphabet on 
only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** findWords(char** words, int wordsSize, int* returnSize) {
	if(words==NULL){
		return NULL;
	}
	int count=0;
	int *indexsave=NULL;
	int i=0;
	int j=0;
	int k=0;
	indexsave=(int *)malloc(wordsSize*sizeof(int));
	const char *keyrow[3];
	keyrow[0]="qwertyuiop";
	keyrow[1]="asdfghjkl";
	keyrow[2]="zxcvbnm";
	for(i=0;i<wordsSize;i++){
		for(j=0;j<3;j++){
			int flag=0;
			for(k=0;k<strlen(words[i]);k++){
				if(!strchr(keyrow[j],words[i][k]) && !strchr(keyrow[j],words[i][k]+32)){
					flag=1;
					break;
				}
			}
			if(flag==0){
				indexsave[count]=i;
				count++;
				break;
			}
		}
	}

	*returnSize=count;
	char **wordsReturn=NULL;
	wordsReturn=(char **)malloc(count*sizeof(char *));
	for(i=0;i<count;i++){
		wordsReturn[i]=(char *)malloc(sizeof(char)*(strlen(words[indexsave[i]])+1));
		strcpy(wordsReturn[i],words[indexsave[i]]);
		strcat(wordsReturn[i],"\0");
	}
	if(indexsave!=NULL){
		free(indexsave);
		indexsave=NULL;
	}

    return wordsReturn;
}

int main(int argc, char const *argv[])
{
	char *words[4];
	words[0]="Hello";
	words[1]="Alaska";
	words[2]="Dad";
	words[3]="Peace";
	int returnSize=0;
	char **wordsReturn=findWords(words,4,&returnSize);
	int i=0;
	for(i=0;i<returnSize;i++){
		printf("%s\n", wordsReturn[i]);
	}
	return 0;
}