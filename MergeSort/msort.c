#include<stdio.h>
#include<stdlib.h>
#include "msort.h"

void merge(student ls1[], int sz1, student ls2[], int sz2, student ls[]){
	int c1=0,c2=0,c=0;
	while(c1<sz1 && c2<sz2){
		ls[c++] = ls1[c1].cgpa < ls2[c2].cgpa ? ls1[c1++] : ls2[c2++];
	}
	while(c1 < sz1){
		ls[c++] = ls1[c1++];
	}
	while(c2 < sz2){
		ls[c++] = ls2[c2++];
	}
}


stud_record readData(char *filename){
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
		return (stud_record){NULL,0};
	char *name = (char *)(malloc(sizeof(char) * 11));
	float cg;
	student *arr = (student *)(malloc(sizeof(student)*5));
	int i=0,size = 5;
	while(fscanf(fp,"%10s,%f",name,&cg) == 2){
		//printf("%s %f\n",name,cg);
		if(i == size){
			size *=2;
			arr = (student *)(realloc(arr,(sizeof(student)*size)));
		}
		arr[i++] = (student){name,cg};
		name = (char *)(malloc(sizeof(char) * 11));
	}
	fclose(fp);
	stud_record sr = {arr,i};
	return sr;
}
	
void printData(stud_record sr){
	for(int i=0;i<sr.size;i++)
		printf("[%s - %f]\n",sr.s[i].name,sr.s[i].cgpa);
	printf("\n");
}
