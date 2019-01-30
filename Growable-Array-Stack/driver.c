#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input text file given!\n");
		return -1;
	}
	FILE *fptr = fopen(argv[1],"r");
	if(fptr==NULL){
		printf("File can't be opened!\n");
		return -1;
	}
	stack *s = newStack();
	int tmp;
	printStackDetails(s);
	while(fscanf(fptr,"%d",&tmp) == 1){
		push(s,tmp);
		printStackDetails(s);
	}
	pop(s);
	printStackDetails(s);
return 0;
}
