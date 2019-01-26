#include<stdio.h>
#include<stdlib.h>
#include "skiplist.h"

int main(int argc, char *argv[]){
	FILE *fptr = fopen(argv[1],"r");
	list *skiplist = (list *) (malloc(sizeof(list)));
	int tmp;
	while(fscanf(fptr,"%d",&tmp) == 1){
		insert(skiplist,tmp);
	}
	printf("Insertions done!\n");
	printList(skiplist);
	printf("%d\n",find(skiplist,46));
	printf("%d\n",find(skiplist,55));
	printf("%d\n",find(skiplist,24));
	printf("%d\n",find(skiplist,19));
return 0;
}
