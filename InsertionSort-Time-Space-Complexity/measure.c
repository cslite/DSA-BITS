#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *lptr;

void capturelptr(int *ptr){
	lptr = ptr;
}

long getStackSpace(int *ptr){
	//printf("%u\n%u\n",ptr,lptr);
	return (long)(ptr - lptr);
}

double gettime(struct timeval t1, struct timeval t2){
	double elapsedtime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedtime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	return elapsedtime;
}
