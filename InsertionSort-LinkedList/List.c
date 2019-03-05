#include "List.h"
#include<sys/time.h>

int globalCnt=0;

void *myalloc(int size){
	int *ptr= (int *)(malloc(size+4));
	ptr[0] = size;
	globalCnt += (size);
	return ((void *)(ptr) + 4);
}

void myfree(void *ptr){
	int *p = (int *)(ptr-4);
	int sz = *p;
	globalCnt -= sz;
	free(p);
}

List createList(Student studArray, int arraySize){
	List l = (List)(myalloc(sizeof(struct list)));
	int i;
	if(arraySize == 0)
		return NULL;
	Node p = (Node)(myalloc(sizeof(struct node)));
	//p->record = (Student)(myalloc(sizeof(struct student)));
	//*(p->record) = studArray[0];
	p->record = studArray;
	l->first = p;
	l->count = 1;
	for(i=1;i<arraySize;i++){
		p->next = (Node)(myalloc(sizeof(struct node)));
		p = p->next;
		//p->record = (Student)(myalloc(sizeof(struct student)));
		//*(p->record) = studArray[i];
		p->record = studArray+i;
		l->count++;
	}
	p->next = NULL;
	l->last = p;
	return l;
}

void insertInOrder(List list, Node newNode){
	Node p = list->first;
	if(list->count == 0){
		list->first = newNode;
		list->last = newNode;
		list->count = 1;
		newNode->next = NULL;
		return;
	}
	float new_marks = newNode->record->marks;
	if(new_marks < p->record->marks){
		//if less than the first node
		newNode->next = p;
		list->first = newNode;
		list->count++;
		return;
	}
	while(p->next != NULL && p->next->record->marks < new_marks){
		p=p->next;
	}
	if(p->next == NULL){
		p->next = newNode;
		(list->count)++;
		list->last = newNode;
		newNode->next = NULL;
		return;
	}
	else{
		newNode->next = p->next;
		p->next = newNode;
		(list->count)++;
		return;
	}
}

List insertionSort(List list){
	if(list->count == 0)
		return list;
	List l = (List)(myalloc(sizeof(struct list)));
	l->count = 0;
	l->first = l->last = NULL;
	Node ptr,pnext;
	for(ptr=list->first;ptr!=NULL;ptr=pnext){
		pnext = ptr->next;
		insertInOrder(l,ptr);
	}
	return l;
}

double measureSortingTime(List list){
	struct timeval t1,t2;
	
	gettimeofday(&t1,NULL);
	
	List sorted = insertionSort(list);
	list->first = sorted->first;
	list->last = sorted->last;
	list->count = sorted->count;
	
	gettimeofday(&t2,NULL);
	
	double passd_time = (t2.tv_sec - t1.tv_sec) * 1000.0;
	passd_time += (t2.tv_usec - t1.tv_usec) / 1000.0;
	
	return passd_time;
}

int getGlobalCnt(){
	return globalCnt;
}
