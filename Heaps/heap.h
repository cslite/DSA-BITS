struct heap{
	int *h;
	int len;
};
typedef struct heap heap;

int parent(int i);
int left(heap hp,int i);
int right(heap hp,int i);
int get(heap hp,int i);
void max_heapify(heap hp, int i);
heap build_max_heap(int *arr, int size);
void heapSort(int *arr, int size);
void printArr(int *arr, int size);
