#include<stdio.h>
#include<stdlib.h>
#include "msort.h"

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	stud_record sr = readData(argv[1]);
	//printData(sr);
	mergeSort(sr.s,sr.size);
	printData(sr);
	return 0;
}
