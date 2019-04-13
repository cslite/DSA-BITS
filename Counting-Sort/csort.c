#include<stdio.h>
#include<stdlib.h>
#include "csort.h"

int *counting_sort(int *arr, int len){
	//each element of arr should be non-negative and maximum value (k) should not be too large, complexity O(k)
	int i;
	int k = arr[0];
	for(i=1;i<len;i++)
		k = (arr[i]>k) ? arr[i] : k;
	// int c[k+1];
	int *c = (int *)(malloc(sizeof(int)*(k+1)));
	int *sorted = (int *)(malloc(sizeof(int)*len));
	for(i=0; i<len;i++)
		c[arr[i]]++;
	for(i=1;i<=k;i++)
		c[i] += c[i-1];
	for(i=len-1;i>=0;i--)
		sorted[--(c[arr[i]])] = arr[i];
	return sorted;
}

void printArr(int *arr, int len){
	for(int i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}