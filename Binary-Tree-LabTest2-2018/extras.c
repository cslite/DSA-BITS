/*******************************************************************
*           DSA Lab Test 2: Problem 1 (extras.c)
*   
*  Implement any support data structures in this file, if required.
* ******************************************************************/
#include "extras.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

	
// Write your code here.


stack createStack(){
	stack s1;
	s1.s = (tree *)(malloc(sizeof(tree)*10));
	s1.noe = 0;
	s1.sz = 10;
	return s1;
}

tree top(stack *s){
	if(s->noe == 0)
		return NULL;
	return (s->s)[s->noe - 1];
}

void push(stack *s, tree key){
	if(s->noe == s->sz){
		s->sz *= 2;
		s->s = (tree *)(realloc(s->s,sizeof(tree)*(s->sz)));
	}
	(s->s)[(s->noe)++] = key;
}

void pop(stack *s){
	if(s->noe > 0)
		s->noe --;
}

bool isEmpty(stack s){
	if(s.noe == 0)
		return true;
	else
		return false;
}

