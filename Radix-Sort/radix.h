typedef struct number{
	int num;
	int residual;
	int key;
} number;

number *createNumberArray(int *arr, int sz);
void radixSort(number *arr, int size);
void printArr(number *arr, int size);