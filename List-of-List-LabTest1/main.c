#include<stdio.h>
#include"node.h"

extern int * Arr[N];
extern int Num_Elements[N];


void PrintArr()
{
  for(int i=0; i<N; i++)
  {
     for(int j = 0; j < Num_Elements[i]; j++)
       printf(" %d ", Arr[i][j]);
     printf("\n");
  }
}

void print(int *arr, int sz){
	for(int i=0;i<sz;i++){
		printf("%d\n",arr[i]);
	}
}

void check(int *arr, int sz){
	for(int i=1; i<sz; i++){
		if(IsLower_GM(arr[i-1],arr[i]) == FALSE && arr[i-1] != arr[i]){
			printf("WRONG!\n");
			return;
		}
	}
	printf("CORRECT!\n");
}

int main()
{
	char fname[15] = "file.txt";
	Locality *l = ReadFileintoLists(fname);
	// PrintLists(l);
	ConvertListstoArray(l);
	// PrintArr();
	InsertionSort_Arr();

	// PrintArr();

	int size = 0;
	for(int i=0;i<N;i++)
		size += Num_Elements[i];
	int *marr = Merge_Arr();

	print(marr,size);
	// check(marr,size);

	// IsLower_GM(450000000, 124456215);
	// IsLower_GM(458790054, 121016215);

return 0;	
}
