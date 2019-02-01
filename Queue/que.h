#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int ele;
	struct node *prev;
	struct node *next;
};

typedef struct node node;

struct Queue{
	int size;
	node *front;
	node *back;
};

typedef struct Queue Queue;

node *newnode(int ele);
Queue *newQ();
bool isEmptyQ(Queue *q);
node *delQ(Queue *q);
node *front(Queue *q);
Queue *addQ(Queue *q, node *e);
int lengthQ(Queue *q);
