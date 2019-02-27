#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

stack newStack(){
	stack s1;
	s1.s = (pair *)(malloc(sizeof(pair)*2));
	s1.size = 2;
	s1.count = 0;
	return s1;
}

int isEmpty(stack s){
	if(s.count == 0)
		return 1;
	else
		return 0;
}

void doubleStack(stack *st){
	st->size *= 2;
	st->s = (pair *)(realloc(st->s,st->size*sizeof(pair)));
}

stack push(stack st, pair ele){
	if(st.count == st.size)
		doubleStack(&st);
	(st.s)[st.count] = ele;
	(st.count)++;
	return st;

}

pair pop(stack *st){
	if(st->count == 0)
		return (pair){-1,-1};
	else{
		(st->count)--;
		return st->s[st->count];
	}
}

pair top(stack st){
	if(st.count == 0)
		return (pair){-1,-1};
	else
		return st.s[st.count - 1];
}
