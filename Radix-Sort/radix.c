#include<stdio.h>
#include<stdlib.h>
#include "radix.h"

number *createNumberArray(int *arr, int sz){
	number *narr = (number *)(malloc(sizeof(number)*sz));
	for(int i=0;i<sz;i++){
		narr[i].num = narr[i].residual = arr[i];
		narr[i].key = -1;
	}
	return narr;
}

void countingSort(number *arr, int size){	//O(n)
	number *narr = (number *)(malloc(sizeof(number)*size));
	int c[10] = {0};
	int i;
	for(i=0;i<size;i++){	//O(n)
		c[arr[i].key]++;
	}
	for(i=1;i<10;i++)		//O(9)
		c[i] += c[i-1];
	for(i=size-1;i>=0;i--){		//O(n)
		narr[--c[arr[i].key]] = arr[i];
	}
	for(i=0;i<size;i++)		//O(n)
		arr[i] = narr[i];
}

void radixSort(number *arr, int size){
	int maxnum = arr[0].num;
	int i;
	
	for(i=0;i<size;i++){	//O(n)
		arr[i].key = arr[i].residual % 10;
		arr[i].residual /= 10;
		if(arr[i].num > maxnum)
			maxnum = arr[i].num;
	}
	while(maxnum){	//O(d*n)	[d is the number of digits in largest number]
		countingSort(arr,size);	// O(n)
		for(i=0;i<size;i++){	//O(n)
			arr[i].key = arr[i].residual % 10;
			arr[i].residual /= 10;
		}
		maxnum /= 10;
	}
}

void printArr(number *arr, int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i].num);
	}
	printf("\n");
}