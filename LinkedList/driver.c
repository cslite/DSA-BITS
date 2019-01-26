#include<stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[]){
	FILE *fptr = fopen(argv[1],"r");
	
	list *head = (list *) malloc(sizeof(list));
	int tmp;
	while(fscanf(fptr,"%d",&tmp) == 1)
	{
		insertFirst(head,tmp);
	}
	printf("Insertions done!\n");
	
	fclose(fptr);
	
	printList(head);
	
	deleteFirst(head);
	
	printList(head);
	
	node *ptr;
	/*
	if(argc > 2){
	
	
		fptr = fopen(argv[2],"w");
	
	
		while((ptr = deleteFirst(head)) != NULL){
			fprintf(fptr,"%d ",ptr->ele);
		}
		
		fclose(fptr);
	}
	*/
	printf("%d ",search(head,45));
	printf("%d ",search(head,47));
	
    deleteR(head,45);
	printList(head);
	
return 0;
}
