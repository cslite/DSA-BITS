#include<stdio.h>
#include<stdlib.h>

// #include "employee.h"
// #include "quicksort.h"
// #include "insertionsort.h"
#include "mixsort.h"

int main(int argc, char *argv[]){
	if(argc==1){
		printf("No input file!\n");
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Cannot open file!\n");
		return -1;
	}
	employee arr[100005];
	int idx=0;
	char name[11];
	int eid;
	while(fscanf(fp,"%s %d",name,&eid)==2){
		arr[idx++] = create_emp(name,eid);
	}
	// print_emp_arr(arr,idx);
	// qs(arr,0,idx-1,3);
	// isort(arr,0,idx-1);
	int best_cutoff = estimateCutoff(arr,0,idx-1,0.0001);
	printf("best cutoff is %d\n",best_cutoff);
	// mixSort(arr,0,idx-1,3);
	// print_emp_arr(arr,idx);
return 0;
}
