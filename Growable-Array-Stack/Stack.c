#include "Stack.h"

stack *newStack(){
	stack *s = (stack *) (malloc(sizeof(stack)));
	s->size = 0;
	s->top = -1;
	s->s = NULL;
return s;
}

int pop(stack *st){
	if(st == NULL)
		return -1;
	if(st->s == NULL || st->top == -1)
		return -1;
	(st->top)--;
	return (st->s)[(st->top)+1];
}

int top(stack *st){
	if(st==NULL)
		return -1;
	if(st->s == NULL || st->top == -1)
		return -1;
	return (st->s)[st->top];
}

void push(stack *st, int ele){
	if(st==NULL){
		printf("No stack available!\n");
		return;
	}
	else if(st->s == NULL){
		st->s = (int *)(malloc(sizeof(int)));
		st->size = 1;
		(st->s)[++(st->top)] = ele;
		return;
	}
	else{
		if(st->top < (st->size - 1)){
			//insertion without resizing
			(st->s)[++(st->top)] = ele;
		}
		else{
			//need to resize
			int new_size = st->size * 2;
			st->s = (int *)(realloc(st->s,new_size*sizeof(int)));
			st->size = new_size;
			(st->s)[++(st->top)] = ele;
		}
	}
}

void printStackDetails(stack *st){
	if(st == NULL){
		printf("No stack provided!\n");
		return;
	}
	if(st->s == NULL){
		printf("Empty Stack!\n");
	}
	if(st->top == -1){
		printf("[Stack Empty, Stack Size = %d]\n",st->size);
		return;
	}
	printf("[top index = %d, top element = %d, Stack size = %d]\n",st->top,top(st),st->size);
}
