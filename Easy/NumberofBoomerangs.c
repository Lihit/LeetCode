/*Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAP_SIZE 500
struct HashMap
{
	int count;
	int val;
	struct HashMap *next;
} disHashMap[MAP_SIZE];


void addToHashMap(int key) {
	int slot = key % MAP_SIZE;
	struct HashMap *p;

	if (disHashMap[slot].val == key) {
		disHashMap[slot].count++;
	} else if (disHashMap[slot].val == 0) {
		disHashMap[slot].val = key;
		disHashMap[slot].count++;
	} else {
		p = &disHashMap[slot];

		while (p->val != key && p->next != NULL) {
			p = p->next;
		}

		if (p->val == key) {
			p->count++;
		} else {
			p->next = (struct HashMap *)malloc(sizeof(struct HashMap));
			p = p->next;
			p->val = key;
			p->count = 1;
			p->next = NULL;
		}
	}

}

int getDistance(int* a, int *b) {
	return abs(a[0] - b[0]) * abs(a[0] - b[0]) + abs(a[1] - b[1]) * abs(a[1] - b[1]);
}

int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
	int i, j, k;
	int ret = 0;
	struct HashMap *p, *toBeFree, *next;
	for (i = 0; i < pointsRowSize; i++) {
		for (k = 0; k < MAP_SIZE; k++) {
			disHashMap[k].val = 0;
			disHashMap[k].count = 0;
			disHashMap[k].next = NULL;
		}
		for (j = 0; j < pointsRowSize; j++) {
			if (i == j) {
				continue;
			}
			addToHashMap(getDistance(points[i], points[j]));
		}
		for (k = 0; k < MAP_SIZE; k++) {
			p = &disHashMap[k];
			while (p != NULL) {
				if (p->count > 1) {
					ret += p->count * (p->count - 1);
				}
				p = p->next;
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	return 0;
}