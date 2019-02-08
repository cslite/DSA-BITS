//MAX HEAP
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "heap.h"

int parent(int i){
	if(!i)	return -1;
	else	return i/2;
}

int left(heap hp,int i){
	int l = 2*i;
	if(l<hp.len)	return l;
	else			return -1;
}

int right(heap hp, int i){
	int r = 2*i + 1;
	if(r<hp.len)	return r;
	else			return -1;	
}

int get(heap hp,int i){
	if(i>=0 && i<hp.len) 	return hp.h[i]; 
	else					return INT_MIN;
}

void max_heapify(heap hp, int i){
	//assumption: left and right subtrees of i are max heaps
	//running time of max_heapify algorithm is O(nlgn)
	int maxi = (get(hp,i) > get(hp,left(hp,i))) ? i : left(hp,i);
	maxi = (get(hp,maxi) > get(hp,right(hp,i))) ? maxi : right(hp,i);
	if(maxi == i)
		return;
	else{
		int tmp = get(hp,maxi);
		hp.h[maxi] = get(hp,i);
		hp.h[i] = tmp;
		max_heapify(hp,maxi);
	}
}

heap build_max_heap(int *arr, int size){
	//running time of this function is actually O(n)
	heap h;
	h.len = size;
	h.h = arr;
	int last_parent = (size/2)-1;
	for(int i=last_parent;i>=0;i--){
		max_heapify(h,i);
	}
	return h;
}

void heapSort(int *arr, int size){
	//build a max heap from the array
	//running time is O(nlgn)
	heap h = build_max_heap(arr,size);
	while(h.len > 1){
		//swap the root with the last element of the array
		int tmp = h.h[h.len - 1];
		h.h[h.len - 1] = h.h[0];
		h.h[0] = tmp;
		//decrease the heap size
		(h.len)--;
		//call the max_heapify on the new node
		max_heapify(h,0);
	}
	
}

void printArr(int *arr, int size){
	for(int i = 0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
