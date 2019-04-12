#include"node.h"
#include<stdio.h>
#include<stdlib.h>
extern int *Arr[N];	//these are N pointers each has to be allocated an array
extern int Num_Elements[N];

void ConvertListstoArray(Locality *start)
{
	if(start == NULL)
		return;
	Locality *lptr;
	Member *mptr;
	int i = 0;
	int j;
	for(lptr = start; lptr != NULL; lptr = lptr->next,i++){
		Num_Elements[i] = lptr->count;
		//allocate space for Members
		Arr[i] = (int *)(malloc(sizeof(int) * Num_Elements[i]));
		j=0;
		for(mptr = lptr->first; mptr != NULL; mptr = mptr->next,j++){
			Arr[i][j] = mptr->id;
		}
	}
 
}
