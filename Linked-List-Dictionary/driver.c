#include<stdio.h>
#include<stdlib.h>
#include "dict.h"

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	dict *db = constructDict(argv[1]);
	if(db == NULL){
		printf("Error reading the file!\n");
		return -1;
	}
	printAll(db);
return 0;
}
