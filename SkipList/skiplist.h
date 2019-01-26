#include<stdio.h>
#include<stdlib.h>

struct node{
	int ele;
	struct node* next;
	struct node* parent;
	int nib;	//nodes in between
};

typedef struct node node;

struct list{
	node *fast_head;
	node *head;
	int count;
};

typedef struct list list;


node *newnode(int ele);
void insert(list *skiplist, int ele);
node *removeX(list *skiplist, int ele);
int find(list *skiplist, int ele);
void printList(list *head);
