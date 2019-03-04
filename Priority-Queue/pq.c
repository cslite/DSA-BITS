#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"pq.h"

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int p(priority_queue pq, int i){
	if(i==0)
		return -1;
	else return i/2;
}

int left(priority_queue pq, int i){
	int l = i*2;
	if(l < pq.sz)
		return l;
	else
		return -1;
}

int right(priority_queue pq, int i){
	int r = (i*2)+1;
	if(r < pq.sz)
		return r;
	else
		return -1;
}

priority_queue create_pq(int ele){
	priority_queue pq;
	pq.h = (int *)(malloc(sizeof(int)*10));
	pq.max_len = 10;
	pq.sz = 1;
	pq.h[0] = ele;
	return pq;
}

int maximum(priority_queue pq){
	if(pq.sz == 0)
		return INT_MIN;
	return pq.h[0];
}

void max_heapify(priority_queue pq, int root){
	if(pq.sz == 0 || root <0 || root >= pq.sz)
		return;
	int max_i;
	if(left(pq,root) != -1 && pq.h[left(pq,root)]>pq.h[root])
		max_i = left(pq,root);
	else
		max_i = root;
	if(right(pq,root) != -1 && pq.h[right(pq,root)] > pq.h[root])
		max_i = right(pq,root);
	if(max_i != root){
		swap(&pq.h[root],&pq.h[max_i]);
		max_heapify(pq,max_i);
	}
}

int extract_max(priority_queue *pq){
	if(pq->sz == 0)
		return INT_MIN;
	swap(&(pq->h[0]),&(pq->h[pq->sz-1]));
	(pq->sz)--;
	max_heapify(*pq,0);
	return pq->h[pq->sz];
}

void increase_key(priority_queue pq, int idx, int k){
	if(idx<0 || idx >= pq.sz)	return;
	if(k <= pq.h[idx])	return;
	pq.h[idx] = k;
	int i = idx;
	while(p(pq,i) != -1 && pq.h[p(pq,i)] < pq.h[i]){
		swap(pq.h + i,pq.h+p(pq,i));
		i = p(pq,i);
	}
}

void insert(priority_queue *pq, int key){
	pq->sz++;
	if(pq->sz == pq->max_len){
		pq->max_len *= 2;
		pq->h = (int *)(realloc(pq->h,sizeof(int)*pq->max_len));
	}
	pq->h[pq->sz - 1] = INT_MIN;
	increase_key(*pq,pq->sz-1,key);
}
