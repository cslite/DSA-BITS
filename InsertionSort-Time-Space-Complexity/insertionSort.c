#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include "measure.h"
#include<string.h>

void insertInOrder(cardinfo ci, cardinfo *arr, int size){
	int i = size;
	int cmpi;
	int cmpim = -999;
	for(;i>0;i--){
		cmpi = cmpim;
		cmpim = strcmp(ci.cno,arr[i-1].cno);
		if(cmpim >= 0 && cmpi < 0){
			arr[i] = ci;
			return;
		}
		else
			arr[i] = arr[i-1];
	}
	arr[0] = ci;
	return;
}

void insertionSort(record r, int sorted_len){
	if(sorted_len < r.size){
		insertInOrder(r.arr[sorted_len],r.arr,sorted_len);
		insertionSort(r,sorted_len + 1);
	}
	else
		capturelptr(&sorted_len);
}
