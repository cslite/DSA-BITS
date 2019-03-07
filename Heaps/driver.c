#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

#define MAX_SIZE 30

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	FILE *fptr = fopen(argv[1],"r");
	if(fptr == NULL){
		printf("Cannot open file!\n");
		return -1;
	}
	int arr[MAX_SIZE];
	int i=1;
	while(i<MAX_SIZE && fscanf(fptr,"%d",&arr[i]) == 1)
		i++;
	i--;
	printArr(arr,i);
	heapSort(arr,i);
	printArr(arr,i);
}
