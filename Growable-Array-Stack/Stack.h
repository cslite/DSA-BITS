#include<stdio.h>
#include<stdlib.h>

struct stack{
	int *s;
	int top;
	int size;
};

typedef struct stack stack;

stack *newStack();
void push(stack *st, int ele);
int pop(stack *st);
int top(stack *st);
void printStackDetails(stack *st);
