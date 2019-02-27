#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "employee.h"
#include "quicksort.h"



int pivot(employee *arr, int lo, int hi){
	return hi;  //choosing pivot can be improved
	// return lo + (hi-lo)/2;
}

void qs(employee arr[], int lo, int hi, int sz){
	stack s = push(newStack(), (pair){lo,hi});
	int p;
	while(!isEmpty(s)){
		pair t = pop(&s);
		lo = t.lo;	hi = t.hi;
		//printf("sc_%d - %d:%d\n",s.count,hi,lo);
		if(sz < 1)
			sz = 0;
		while(hi-lo > sz){
			p = pivot(arr,lo,hi);
			p = partition(arr,lo,hi,p);
			if(p-1-lo > sz)
				s = push(s, (pair){lo,p-1});
			lo = p+1;
		}
	}
}

void swap(employee *e1, employee *e2){
	employee etmp = *e1;
	*e1 = *e2;
	*e2 = etmp;
}

int partition(employee *arr, int lo, int hi, int p){
	int i=lo,j=hi;
	swap(arr+hi,arr+p);
	// employee tmp = arr[hi];
	// arr[hi] = arr[p];
	// arr[p] = tmp;
	p = hi;
	j--;
	while(i<j){
		if(getkey(arr,i) <= getkey(arr,p)){
			i++; continue;
		}
		if(getkey(arr,j) > getkey(arr,p)){
			j--; continue;
		}
		swap(arr+j,arr+i);
		// tmp = arr[j];
		// arr[j] = arr[i];
		// arr[i] = tmp;
		i++; j--;
	}
	if(getkey(arr,i) > getkey(arr,p)){
		swap(arr+i,arr+p);
		return i;
	}
	else{
	swap(arr+i+1,arr+p);
	// tmp = arr[i+1];
	// arr[i+1] = arr[p];
	// arr[p] = tmp;
	// p = i+1;
	return i+1;
	}
}
