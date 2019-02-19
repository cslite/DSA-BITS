#include<stdio.h>
#include<stdlib.h>
#include "msort.h"

student *sarr;

void merge_sort(student ls[], int sz){
	if(sz == 1)
		return;
	int mid = sz/2;
	merge_sort(ls,mid);
	merge_sort(ls+mid,sz-mid);
	merge(ls,mid,ls+mid,sz-mid,sarr);
	for(int i=0;i<sz;i++)
		ls[i] = sarr[i];
}

void mergeSort(student ls[], int sz){
	sarr = (student *) (calloc(sz, sizeof(student)));
	merge_sort(ls,sz);
}
