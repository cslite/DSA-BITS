#include<stdio.h>
#include<stdlib.h>
#include "msort.h"

student *sarr;

void merge_sort(student ls[], int sz){
	int msize = 2;
	if(sz==1)	return;
	while(msize <= sz){
		int k = 0;
		int n = (sz/msize)*msize;
		for(k=0;k<n;k+=msize){
			int sp = msize/2;
			merge(ls+k,sp,ls+k+sp,msize-sp,sarr);
			for(int i=0;i<msize;i++)
				ls[i+k] = sarr[i];
		}
		if(n!=sz){
			merge(ls+k-msize,msize,ls+k,sz-k,sarr);
			for(int i=0;i<(msize+sz-k);i++)
				ls[i+k-msize] = sarr[i];
		}
		msize *= 2;
	}
	msize /= 2;
	if(msize == sz)	return;
	merge(ls,msize,ls+(msize),sz-(msize),sarr);
	for(int i=0;i<sz;i++)
		ls[i] = sarr[i];
	
}

void mergeSort(student ls[], int sz){
	sarr = (student *) (calloc(sz, sizeof(student)));
	merge_sort(ls,sz);
}
