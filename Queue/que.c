#include "que.h"

node *newnode(int ele){
	node *n = (node *)(malloc(sizeof(node)));
	n->ele = ele;
	n->next = NULL;
	n->prev = NULL;
return n;
}

Queue *newQ(){
	Queue *q = (Queue *)(malloc(sizeof(Queue)));
	q->size = 0;
	q->front = NULL;
	q->back = NULL;
return q;
}

bool isEmptyQ(Queue *q){
	if(q==NULL)
		return true;
	else if(q->size == 0)
		return true;
	else
		return false;
}

node *front(Queue *q){
	if(q==NULL)
		return NULL;
	else if(q->size == 0)
		return NULL;
	else return q->front;
}

int lengthQ(Queue *q){
	if(q==NULL)
		return 0;
	else return q->size;
}

node *delQ(Queue *q){
	//delete from the first & return deleted element
	if(q==NULL)
		return NULL;
	else if(q->size == 0)
		return NULL;
	else{
		node *tmp = q->front;
		if(q->size == 1){
			q->front = NULL;
			q->back = NULL;
		}
		else{
			q->front = q->front->next;
			q->front->prev = NULL;
		}
		(q->size)--;
		return tmp;
	}
}

Queue *addQ(Queue *q, node *e){
	if(q==NULL||e==NULL)
		return NULL;
	else if(q->size == 0){
		q->front = q->back = e;
		(q->size)++;
		return q;
	}
	else{
		q->back->next = e;
		e->prev = q->back;
		(q->size)++;
		q->back = e;
		return q;
	}		
}
