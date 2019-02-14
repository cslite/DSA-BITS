#include<stdio.h>
#include<stdlib.h>
#include "card.h"
#include<string.h>

cardinfo genci(char *str){
	//it will be given a string wiht all info for a record
	cardinfo ci;
	int i = 0;
	if(str[i] == '"')
		i++;
	else{
		printf("Wrong format string!\n");
		return ci;
	}
	int c = 0;
	while(str[i] != ','){
		ci.cno[c++] = str[i++];
	}
	ci.cno[c]  = '\0';
	i++;
	c = 0;
	while(str[i] != ','){
		ci.bankcode[c++] = str[i++];
	}
	ci.bankcode[c] = 0;
	i++;
	char my[5];
	c = 0;
	while(str[i] != '/'){
		my[c++] = str[i++];
	}
	my[c] = '\0';
	ci.exp_m = atoi(my);
	i++;
	c=0;
	while(str[i] != ','){
		my[c++] = str[i++];
	}
	my[c] = 0;
	ci.exp_y = atoi(my);
	i++;
	c=0;
	while(str[i] != ','){
		ci.fname[c++] = str[i++];
	}
	ci.fname[c] = 0;
	i++;	c=0;
	while(str[i] != '"'){
		ci.lname[c++] = str[i++];
	}
	ci.lname[c] = 0;
	return ci;
}


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
