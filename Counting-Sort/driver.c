#include<stdio.h>
#include<stdlib.h>
#include "csort.h"
#include <limits.h>

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Can't open file!\n");
		return -1;
	}
	int arr[32768];
	int tmp;
	int i = 0;
	while(fscanf(fp,"%d",&tmp) == 1){
		arr[i++] = tmp;
	}
	printArr(arr,i);
	int *sorted = counting_sort(arr,i);
	printArr(sorted,i);
return 0;
}