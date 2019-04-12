#include<stdio.h>
#include<stdlib.h>
#include"node.h"

extern int * Arr[N];
extern int Num_Elements[N];

void Merge_GM(int *Ls1, int sz1, int * Ls2, int sz2, int* Ls)
{
  int c1=0,c2=0,c=0;
  while(c1 < sz1 && c2 < sz2){
  	Ls[c++] = IsLower_GM(Ls1[c1],Ls2[c2]) ? Ls1[c1++] : Ls2[c2++];
  }
  while(c1 < sz1){
  	Ls[c++] = Ls1[c1++];
  }
  while(c2 < sz2){
  	Ls[c++] = Ls2[c2++];
  }
}


//this function on each call merge pairs of arrays and make a new set of arrays
int *msort(int *a[], int numele[], int sz){
	int newsz = sz/2;
	if(sz%2 != 0) newsz++;

	int **b = (int **)(malloc(sizeof(int *)*newsz));
	int *bnum = (int *)(malloc(sizeof(int) * newsz));
	int i,c=0;
	for(i=0;i<sz-1;i+=2){
		bnum[c] = numele[i] + numele[i+1];
		b[c] = (int *)(malloc(sizeof(int)*bnum[c]));
		Merge_GM(a[i],numele[i],a[i+1],numele[i+1],b[c]);
		
		//free the previously created temp array
		free(a[i]);
		free(a[i+1]);

		c++;
	}
	if(sz%2 != 0){
		b[c] = a[sz - 1];
		bnum[c] = numele[sz-1];
		c++;
	}
	//now we have a b array with double sized arrays and bnum array with sizes
	
	//As Num_Elements and Arr can't be freed
	if(numele != Num_Elements)
		free(numele);
	if(a != Arr)
		free(a);

	if(newsz == 1)	//that means sz was 2 and this is the base case
		return b[0];
	else
		return msort(b,bnum,newsz);
}

int *Merge_Arr()
{

	return msort(Arr,Num_Elements,N);
      // int size;
      // int *l1 = Arr[0];
      // int sz1 = Num_Elements[0];
      // int *l2;
      // int sz2;
      // for(int i=1;i<N;i++){
      // 	sz2 = sz1 + Num_Elements[i];
      // 	l2 = (int *)(malloc(sizeof(int) * sz2));
      // 	Merge_GM(l1,sz1,Arr[i],Num_Elements[i],l2);
      	
      // 	if(l1 != Arr[0])	//free all the temporary lists
      // 		free(l1);
      	
      // 	l1 = l2;
      // 	sz1 = sz2;
      // }
      // return l1;
}


