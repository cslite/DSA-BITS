#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include "measure.h"
#include "insertionSort.h"
#include <sys/time.h>

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	struct timeval t1,t2;
	double elapsedtime;
	FILE *fp = fopen("output.txt","a");
	gettimeofday(&t1,NULL);
	
	record r = insert_data(argv[1]);
	if(r.size == 0){
		return -1;
	}
	
	gettimeofday(&t2,NULL);
	elapsedtime = gettime(t1,t2);
	printf("%s: Total time for insertion is %lf ms.\n",argv[1],elapsedtime);
	fprintf(fp,"%s: Total time for insertion is %lf ms.\n",argv[1],elapsedtime);
	//printRecord(r);
	
	gettimeofday(&t1,NULL);
	
	insertionSort(r,1);
	
	gettimeofday(&t2,NULL);
	
	elapsedtime = gettime(t1,t2);
	
	printf("%s: Total time for sorting is %lf ms.\n",argv[1],elapsedtime);
	fprintf(fp,"%s: Total time for sorting is %lf ms.\n",argv[1],elapsedtime);

	long ss = getStackSpace(&argc);
	
	printf("%s: Approx. Stack Space consumed during the sort is %ld.\n\n",argv[1],ss);
	fprintf(fp,"%s: Approx. Stack Space consumed during the sort is %ld.\n\n",argv[1],ss);
	
	fclose(fp);
	//printRecord(r);
	
	return 0;
}
