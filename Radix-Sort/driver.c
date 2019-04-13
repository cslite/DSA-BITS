#include<stdio.h>
#include<stdlib.h>
#include"radix.h"

#define MAX 200

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Unable to open file!\n");
		return -1;
	}
	int arr[MAX];
	int i=0,tmp;
	while(fscanf(fp,"%d",&tmp) == 1){
		arr[i++] = tmp;
	}
	number *narr = createNumberArray(arr,i);
	printArr(narr,i);
	radixSort(narr,i);
	printArr(narr,i);

return 0;
}