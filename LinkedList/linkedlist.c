#include "linkedlist.h"
#include <stdlib.h>

void insertFirst(list *head, int ele)
{
	node *n = (node *) malloc(sizeof(node));
	n->ele = ele;
	if(head == NULL)
		printf("No list was provided!\n");
	if(head->first == NULL){
		n->next = NULL;
		head->first = n;
		(head->count)++;
	}
	else{
		n->next = head->first;
		head->first = n;
		(head->count)++;
	}
}

node *deleteFirst(list *head){
	if(head == NULL)
		printf("No list was provided!\n");
	if(head -> first != NULL){
		node *tmp = head->first;
		head->first = head->first->next;
		(head->count)--;
		return tmp;
	}
	return NULL;
}

void printList(list *head){
	if (head== NULL)
		return;
	node *tmp = head->first;
	while(tmp!=NULL){
		printf("%d -> ",tmp->ele);
		tmp = tmp->next;
	}
	printf("End\n");
}

int search(list *head, int ele){
	if(head == NULL)
		return 0;
	node *ptr = head->first;
	while(ptr != NULL)
	{
		if(ele == ptr->ele)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}

node *deleteR(list *head, int ele){
	if(head != NULL){
		node *ptr = head->first;
		//printf("%d\n",ele);
		while(ptr->next != NULL && (ptr->next->ele) != ele){
			//printf("dBug %d\n",ptr->next->ele);
			ptr = ptr->next;
		}
		if(ptr->next != NULL){
			node *tmp = ptr->next;
			ptr->next = ptr->next->next;
			(head->count)--;
			return tmp;
		}
	}
	printf("Error!\n");
	return 	NULL;
}
