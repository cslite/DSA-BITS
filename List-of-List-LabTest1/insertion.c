#include "node.h"
#include<stdio.h>

extern int * Arr[N];
extern int Num_Elements[N];

void InsertionSort_GM(int arr[], int n) 
{
	if(n<=1)
		return;
	int lo,hi;
	lo = 0;
	hi = n-1;
	int tmp_hi;
	for(tmp_hi = lo+1; tmp_hi <= hi; tmp_hi++){
		int tmp = arr[tmp_hi];
		int i = tmp_hi -1;
		while(i>=0 && IsLower_GM(tmp,arr[i])){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = tmp;
	}
 	
} 

void InsertionSort_Arr()
{
	int i;
	for(i=0;i<N;i++){
		InsertionSort_GM(Arr[i],Num_Elements[i]);
	}

}
