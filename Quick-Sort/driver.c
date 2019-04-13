#include<stdio.h>
#include<stdlib.h>
#include"qsort.h"

int main(){
	int arr[10] = {6,4,2,9,22,7,45,12,33,5};
	quicksort(arr,0,9);
	for(int i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");
return 0;
}
