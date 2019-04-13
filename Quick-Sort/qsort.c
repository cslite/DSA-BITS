#include<stdio.h>
#include<stdlib.h>
#include"qsort.h"
#include<time.h>


void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void rand_pivot(int *arr, int lo, int hi){
	//it randomly chooses a pivot and places at hi
	srand(time(0));
	int rand_idx = (rand()%(hi-lo+1)) + lo;
	printf("lo=%d, hi=%d, pivot=arr[%d]=%d\n",lo,hi,rand_idx,arr[rand_idx]);
	swap(arr+rand_idx,arr+hi);
}

void median3_pivot(int *arr, int lo, int hi){
	int mid = lo + (hi-lo)/2;
	printf("lo->arr[%d]=%d, hi->arr[%d]=%d, mid->arr[%d]=%d",lo,arr[lo],hi,arr[hi],mid,arr[mid]);
	if(arr[lo] > arr[mid])
		swap(arr+lo,arr+mid);
	if(arr[mid] > arr[hi])
		swap(arr+mid,arr+hi);
	if(arr[lo] > arr[mid])
		swap(arr+lo,arr+mid);
	printf(", pivot=%d\n",arr[mid]);
	swap(arr+mid,arr+hi);
}

// void median3_pivot(int *arr, int lo, int hi){
// 	int mid = lo + (hi-lo)/2;
// 	int a3[3] = {arr[lo],arr[mid],arr[hi]};
// 	int idx[3] = {lo,mid,hi};
// 	if(a3[0] > a3[1]){
// 		swap(a3,a3+1);
// 		swap(idx,idx+1);
// 	}
// 	if(a3[1] > a3[2]){
// 		swap(a3+1,a3+2);
// 		swap(idx+1,idx+2);
// 	}
// 	int fidx = a3[1] > a3[0] ? idx[1] : idx[0];
// 	printf("lo->arr[%d]=%d, hi->arr[%d]=%d, mid->arr[%d]=%d, pivot=arr[%d]=%d\n",lo,arr[lo],hi,arr[hi],mid,arr[mid],fidx,arr[fidx]);
// 	swap(arr+fidx,arr+hi);
// }

int partition(int *arr, int lo, int hi){
	//partition function that returns the location of pivot after partitioning
	rand_pivot(arr,lo,hi);
	// median3_pivot(arr,lo,hi);
	int p = arr[hi];	//pivot
	int i = lo-1;
	for(int j=lo;j<hi;j++){	//loop from lo to last 2nd element
		if(arr[j]<=p){
			i++;
			swap(arr+i,arr+j);
		}
	}	
	swap(arr+i+1,arr+hi);
	return i+1;
}

//recursive implementation of quick sort
void quicksort(int *arr, int lo, int hi){
	if(lo<hi){
		int q = partition(arr,lo,hi);
		quicksort(arr,lo,q-1);
		quicksort(arr,q+1,hi);
	}
}
