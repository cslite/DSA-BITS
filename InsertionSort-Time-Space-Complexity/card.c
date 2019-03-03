#include<stdio.h>
#include<stdlib.h>
#include "card.h"
#include<string.h>

record insert_data(char *filename){
	FILE *fptr = fopen(filename,"r");
	if(fptr == NULL){
		printf("File cannot be opened!\n");
		return (record){NULL,0};
	}
	int size = 2;
	int len = 0;
	cardinfo *arr = (cardinfo *)(malloc(2* sizeof(cardinfo)));
	int idx=0;
	char str[100];
	while(fscanf(fptr,"%s",str) == 1){
		if(str[0] == '"')
			len++;
		else
			return (record){NULL,0};
		cardinfo tmp = genci(str);
		if(idx < size)
			arr[idx++] = tmp;
		else{
			size *= 2;
			arr = (cardinfo *)(realloc(arr,size*sizeof(cardinfo)));
			arr[idx++] = tmp;
		}
	}
	record r = {arr,len};
	fclose(fptr);
	return	r;
}

void printci(cardinfo ci){
	printf("CardNumber: %s\n",ci.cno);
	printf("BankCode: %s\n", ci.bankcode);
	printf("Expiry: %d/%d\n",ci.exp_m,ci.exp_y);
	printf("Name: %s %s\n",ci.fname,ci.lname);
}

void printRecord(record r){
	for(int i=0;i<r.size;i++){
		printci(r.arr[i]);
		printf("\n");
	}
}
