#include<stdio.h>
#include<stdlib.h>

struct node{
	int ele;
	struct node* next;
};

typedef struct node node;

struct list{
	node *head;
	int count;
};

typedef struct list list;

node *newnode(int ele){
	node *ptr = (node *)(malloc(sizeof(node)));
	ptr->ele = ele;
	ptr->next = NULL;
	return ptr;
}

void insert(list *linkedlist, int ele){
	//insert at the first position
	if(linkedlist == NULL)
		return;
	node *elenode = newnode(ele);
	if(linkedlist->head == NULL){
		linkedlist->head = elenode;
		(linkedlist->count)++;
	}
	else{
		elenode->next = linkedlist->head;
		linkedlist->head = elenode;
		(linkedlist->count)++;
	}
}

int doTheyMerge(list *l1, list *l2){
	//this just checks whether the given two lists merge or not
	node *n1 = l1->head;
	node *n2 = l2->head;
	if(n1==NULL || n2==NULL)
		return 0;
	for(;n1->next != NULL;n1=n1->next);
	for(;n2->next != NULL;n2=n2->next);
	if(n1==n2)
		return 1;
	else
		return 0;
}

void merge(long *arr, int si, int mid, int ei){
	int ptr1 = si;
	int ptr2 = mid+1;
	long tmp[ei-si+1];
	int c=0;
	while(ptr1 <= mid && ptr2 <= ei){
		 if(arr[ptr1] < arr[ptr2])
		 	tmp[c++] = arr[ptr1++];
		 else
		 	tmp[c++] = arr[ptr2++];
	}
	if(ptr1>mid){
		while(ptr2<=ei){
			tmp[c++] = arr[ptr2++];
		}
	}
	if(ptr2>ei){
		while(ptr1<=mid){
			tmp[c++] = arr[ptr1++];
		}
	}
	for(int i=0; i<c;i++){
		arr[si+i] = tmp[i];
	}
}

void printArr(long *arr, int size){
	for(int i=0;i<size;i++){
		printf("%ld, ",arr[i]);
	}
	printf("\n");
}

void sort(long *arr,int si, int ei){
	//si is start_idx, ei is end_idx
	if(si<ei){
		int mid = si + ((ei-si)/2);
		sort(arr,si,mid);
		sort(arr,mid+1,ei);
		merge(arr,si,mid,ei);
		//printf("(%d,%d) ",si,ei);
		//printArr(arr,11);
	}
}

int binsearch(long *arr, int size, long key){
	int l = 0;
	int r = size-1;
	int mid;
	while(l<=r){
		mid = l + (r-l)/2;
		if(arr[mid] < key)
			l = mid + 1;
		else if(arr[mid] > key)
			r = mid -1;
		else
			return 1;
		}
	return 0;
}

node *getMergePt(list *l1, list *l2){
	list *sl, *ll;
	if(l1->count < l2->count){
		sl = l1;
		ll = l2;
	}
	else{
		sl = l2;
		ll = l1;
	}
	long addr[sl->count];
	int i;
	node *ptr = sl->head;
	for(i=0;i<(sl->count);i++){
		addr[i] = (long)(ptr);
		ptr = ptr->next;
	}
	int ei = (sl->count) -1;
	//printArr(addr,sl->count);
	sort(addr,0,ei);
	//printArr(addr,sl->count);
	ptr = ll->head;
	while(ptr!=NULL){
		if(binsearch(addr,sl->count,(long)ptr) == 1)
			return (node *) ptr;
		ptr = ptr->next;
	}
	return NULL;
}

void printList(list *l){
	node *ptr = l->head;
	while(ptr != NULL){
		printf("%d -> ",ptr->ele);
		ptr = ptr->next;
	}
	printf("End\n");
}

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input text file given!\n");
		return -1;
	}
	FILE *fptr = fopen(argv[1],"r");
	if(fptr==NULL){
		printf("File can't be opened!\n");
		return -1;
	}
	long arr[15];
	int i=0;
	while((fscanf(fptr,"%ld",&arr[i++])==1) && i<14);
	//printArr(arr,i-1);
	//sort(arr,0,i-2);
	//printArr(arr,i-1);
	//printf("%d..\n",binsearch(arr,i-1,233));
	list *l1 = (list *)(malloc(sizeof(list)));
	list *l2 = (list *)(malloc(sizeof(list)));
	insert(l1,arr[0]);
	insert(l1,arr[1]);
	l2->head = l1->head;
	l2->count = l1->count;
	int j;
	for(j=2;j<5;j++)
		insert(l2,arr[j]);
	for(j=5;j<(i-1);j++)
		insert(l1,arr[j]);
	printList(l1);
	printList(l2);
	printf("%d\n",doTheyMerge(l1,l2));
	node *mp = getMergePt(l1,l2);
	if(mp==NULL)
		printf("They do not merge!\n");
	else
		printf("they merge at ele=%d\n",mp->ele);
	//printf("%lld\n",(long long)l1->head);
	//printf("%lld\n",(long long)l2->head);
return 0;
}
