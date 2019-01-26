#include "skiplist.h"
#define MAX_NIB 8

node *newnode(int ele){
	node *ptr = (node *)(malloc(sizeof(node)));
	ptr->ele = ele;
	ptr->next = NULL;
	ptr->parent = NULL;
	ptr->nib = 0;
	return ptr;
}

void balanceit(node *curr, node *prev){
	node *currslow, *prevslow;
	int idx = (MAX_NIB/2);
	int i;
	currslow = prev->parent;
	for(i=0;i<idx;i++)
	{
		prevslow = currslow;
		currslow = currslow->next;
	}
	node *fastnode = newnode(currslow->ele);
	fastnode->next = curr;
	fastnode->parent = currslow;
	prev->next = fastnode;
	fastnode->nib = idx-1;
	curr->nib = ((curr->nib) - 1) - fastnode->nib ;
}

void insert(list *skiplist, int ele){
	node *fastnode = newnode(ele);
	node *slownode = newnode(ele);
	fastnode->parent = slownode;
	if(skiplist->count==0){
		skiplist->fast_head = fastnode;
		skiplist->head = slownode;
		(skiplist->count)++;
		return;
	}
	if(skiplist->count==1){
		if(ele > skiplist->fast_head->ele){
			skiplist->fast_head->next = fastnode;
			skiplist->head->next = slownode;
		}
		else{
			fastnode->next = skiplist->fast_head;
			slownode->next = skiplist->head;
			skiplist->fast_head = fastnode;
			skiplist->head = slownode;
		}
		(skiplist->count)++;
		return;
	}
	node *currptr, *prevptr;
	if(skiplist->fast_head->ele > ele){
		//insertion at first position
		slownode->next = skiplist->head;
		fastnode->next = skiplist->fast_head->next;
		if(fastnode->next != NULL)
			(fastnode->next->nib)++;
		skiplist->head = slownode;
		skiplist->fast_head = fastnode;
		prevptr = skiplist->fast_head;
		currptr = skiplist->fast_head->next;
	}
	else{
		for(currptr=skiplist->fast_head;(currptr->next != NULL && currptr->next->ele < ele);prevptr=currptr,currptr=currptr->next);
		if(currptr->next == NULL){
			//greater than the last element
			currptr->parent->next = slownode;
			fastnode->nib = (currptr->nib) + 1;
			prevptr->next = fastnode;
		}
		else{
			// insertion in between
			prevptr = currptr;
			currptr = currptr->next;
			node *currslow;
			currslow = prevptr->parent;
			for(;(currslow->next->ele < ele); currslow=currslow->next);
			slownode->next = currslow->next;
			currslow->next = slownode;
			(currptr->nib)++;
		}
	}
	(skiplist->count)++;
	if(currptr != NULL && currptr->nib > MAX_NIB)
		balanceit(currptr,prevptr);
}

int find(list *skiplist, int ele){
	node *start, *end, *curr;
	if(ele < skiplist->fast_head->ele)
		return 0;
	//printf("Starting at the fast lane,\n");
	for(curr=skiplist->fast_head;(curr->next != NULL && curr->next->ele < ele); curr=curr->next);
		//printf("%d -> ",curr->ele);
	if(curr->next == NULL)
		return 0;
	end = curr->next->parent;
	start = curr->parent;
	//printf("\n Moved to slow lane,\n");
	for(curr=start;(curr->next != end && curr->next->ele < ele);curr=curr->next);
		//printf("%d -> ",curr->ele);
	//printf("\n");
	if(curr->next != NULL && curr->next->ele == ele)
		return 1;
	else
		return 0;
}

node *removeX(list *skiplist, int ele){
	printf("This function is under construction, sorry!\n");
	return NULL;
}
	
void printList(list *head){
	if (head== NULL)
		return;
	node *tmp = head->fast_head;
	while(tmp!=NULL){
		printf("%d_(%d) -> ",tmp->ele,tmp->nib);
		tmp = tmp->next;
	}
	printf("End\n");
	tmp = head->head;
	while(tmp!=NULL){
		printf("%d -> ",tmp->ele);
		tmp=tmp->next;
	}
	printf("End\n");
}
