/*******************************************************************
*           DSA Lab Test 2: Problem 1 (extras.h)
*   
*  Implement any support data structures in this file, if required.
* ******************************************************************/

#include "tree.h"
#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

// Write your code here.

struct stack{
	tree *s;
	int noe;
	int sz;
};

typedef struct stack stack;

stack createStack();
tree top(stack *s);
void push(stack *s, tree key);
void pop(stack *s);
bool isEmpty(stack s);
	

#endif // EXTRAS_H_INCLUDED
