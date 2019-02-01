#include<stdio.h>
#include "que.h"

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input File!\n");
		return -1;
	}
	FILE *fptr = fopen(argv[1],"r");
	if(fptr == NULL){
		printf("Cannot open file!\n");
		return -1;
	}
	int tmp;
	Queue *q = newQ();
	printf("isQueueEmpty() = %d\n",isEmptyQ(q));
	while(fscanf(fptr,"%d",&tmp) == 1){
		node *ptr = newnode(tmp);
		q = addQ(q,ptr);
		printf("Inserted %d...\n",q->back->ele);
	}
	printf("Now length is %d.\n",lengthQ(q));
	delQ(q);
	printf("Now length is %d.\n",lengthQ(q));
	printf("Now front is %d...\n",front(q)->ele);
return 0;
}
