#include<stdio.h>
#include<stdlib.h>
#include "mixsort.h"
#include "insertionsort.h"
#include "quicksort.h"
#include <sys/time.h>


void mixSort(employee *arr, int lo, int hi, int cutoff){
	qs(arr,lo,hi,cutoff);
	isort(arr,lo,hi);
}

double gettimediff(struct timeval t1, struct timeval t2){
	double elapsedtime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedtime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	return elapsedtime;
}

dub2 testRun(employee *arr, int lo, int hi, int cutoff){
	employee *arr_cpy = (employee *)(malloc(sizeof(employee)*(hi-lo+1)));
	for(int i=lo;i<=hi;i++)
		arr_cpy[i] = arr[i];
	struct timeval t1,t2;
	dub2 tstats;
	gettimeofday(&t1,NULL);
	
		qs(arr_cpy,lo,hi,cutoff);

	gettimeofday(&t2,NULL);

	tstats.qst = gettimediff(t1,t2);

	gettimeofday(&t1,NULL);

		isort(arr_cpy,lo,hi);

	gettimeofday(&t2,NULL);

	tstats.ist = gettimediff(t1,t2);

	return tstats;
}

double getdiff(dub2 tmp){
	return (tmp.ist - tmp.qst);
}

double absdb(double val){
	return val>0 ? val : (val*-1);
}

int estimateCutoff(employee *arr, int lo, int hi, double difflimit){
	int min = 0;
	int max = hi-lo+1;
	dub2 tt1 = testRun(arr,lo,hi,min);	//insertion sort should be cheap
	printf("{min=%d; ist=%lf, qst=%lf; diff=%lf}\n",min,tt1.ist,tt1.qst,getdiff(tt1));
	if(tt1.ist > tt1.qst)			
		printf("Aise Kaise IS!\n");
	dub2 tt2 = testRun(arr,lo,hi,max);	//quicksort should be cheap
	printf("{max=%d; ist=%lf, qst=%lf; diff=%lf}\n",max,tt2.ist,tt2.qst,getdiff(tt2));
	if(tt2.qst > tt2.ist)
		printf("Aise Kaise QS!\n");
	int mid;
	double min_diff = absdb(getdiff(tt1)) < absdb(getdiff(tt2)) ? absdb(getdiff(tt1)) : absdb(getdiff(tt2));
	int min_mid;
	while(min < max){
		mid = min + (max-min)/2;
		dub2 tt = testRun(arr,lo,hi,mid);
		double diff = getdiff(tt);
		if(absdb(diff) < min_diff){
			min_diff = absdb(diff);
			min_mid = mid;
		}
		printf("{mid=%d; ist=%lf, qst=%lf; diff=%lf}\n",mid,tt.ist,tt.qst,diff);
		if(absdb(diff) < difflimit)
			return mid;
		if(getdiff(tt) > 0)
			max = mid;
		else
			min = mid;
	}
	return min_mid;
}
