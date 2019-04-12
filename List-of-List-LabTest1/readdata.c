#include"node.h"
#include<stdio.h>
#include<stdlib.h>


Locality * ReadFileintoLists(char *filename)
{
	if(filename == NULL)
		return NULL;

	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
		return NULL;

	int i,j;
	
	Locality *head = NULL;
	Locality *lptr = NULL;
	Member *mptr = NULL;
	
	if(N==0)
		return NULL;
	
	//for first node
	head = (Locality *)(malloc(sizeof(Locality)));
	head->count = 0;


	
	//get count for first node
	fscanf(fp,"%d",&(head->count));
	
	//allocate memory for first member node of head locality node
	head->first = (Member *)(malloc(sizeof(Member)));
	//get first member's id
	fscanf(fp,",%d",&(head->first->id));
	
	mptr = head->first;
	
	//add all members to the member linked list of head locality node
	for(j=1;j<(head->count);j++){
		mptr->next = (Member *)(malloc(sizeof(Member)));
		mptr = mptr->next;
		fscanf(fp,",%d",&(mptr->id));
	}
	
	//point last member's next to NULL
	mptr->next = NULL;

	//lptr is our temp locality pointer
	lptr = head;
	for(i=1;i<N;i++){
		lptr->next = (Locality *)(malloc(sizeof(Locality)));
		lptr = lptr->next;
		fscanf(fp,"%d",&(lptr->count));
		
		lptr->first = (Member *)(malloc(sizeof(Member)));
		fscanf(fp,",%d",&(lptr->first->id));
		mptr = lptr->first;

		for(j=1;j<(lptr->count);j++){
			mptr->next = (Member *)(malloc(sizeof(Member)));
			mptr = mptr->next;
			fscanf(fp,",%d",&(mptr->id));

		}
		mptr->next = NULL;
	}

	return head;

}

void PrintLists (Locality *start)
{
	if(start == NULL)
		return;
	Locality *lptr;
	Member *mptr;
	for(lptr = start; lptr != NULL; lptr = lptr->next){
		printf("(count=%d)",lptr->count);
		for(mptr = lptr->first; mptr != NULL; mptr = mptr->next){
			printf("->(%d)",mptr->id);
		}
		printf("\n");
	}

}
