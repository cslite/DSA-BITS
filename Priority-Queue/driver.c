#include<stdio.h>
#include<stdlib.h>
#include"pq.h"

void printArr(priority_queue pq){
	for(int i=0;i<pq.sz;i++)
		printf("%d ",pq.h[i]);
	printf("\n");
}

int main(){
	priority_queue pq = create_pq(1);
	printArr(pq);
	printf("%d\n",maximum(pq));
	insert(&pq,5);
	insert(&pq,10);
	printArr(pq);
	insert(&pq,3);
	printArr(pq);
	printf("%d\n",extract_max(&pq));
	insert(&pq,7);
	printArr(pq);
return 0;
}
	
