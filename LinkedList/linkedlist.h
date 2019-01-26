#include<stdio.h>

struct node{
	int ele;
	struct node* next;
};

struct list{
	int count;
	struct node *first;
};

typedef struct list list;
typedef struct node node;

void insertFirst(list *head, int ele);
node *deleteFirst(list *head);
void printList(list * head);
int search(list *head, int ele);
node *deleteR(list *head, int ele);
