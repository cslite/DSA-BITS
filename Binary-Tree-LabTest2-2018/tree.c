/******************************************************
*           DSA Lab Test 2: Problem 1 (tree.c)
*   
*     Only fill up the missing function definitions.
* ****************************************************/
#include "tree.h"
#include "extras.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

unsigned int* createList(unsigned int p)
{
    unsigned int *list = NULL;
    
    // Write your code here.
    list = (unsigned int *)(malloc(sizeof(unsigned int)*p));
    int i;
    for(i=0;i<p;i++){
    	list[i] = rand();
    }
    return list;
    
}

tree constructTree(unsigned int *list, unsigned int len)
{
    tree t = NULL;
    
    // Write your code here.
    if(len == 0)
    	return NULL;
    t = (tree)(malloc(sizeof(struct _tnode)));
    t->data = list[0];
    t->left = t->right = NULL;
    enum probability p1 = rand()%3;
    switch(p1){
    	case LEMPTY:
    		t->left = constructTree(list+1,len-1);
    		break;
    	case REMPTY:
    		t->right = constructTree(list+1,len-1);
    		break;
    	case NONEMPTY:
    		t->left = constructTree(list+1,(len-1)/2);
    		t->right = constructTree(list+1+((len-1)/2),len-1-((len-1)/2));
    		break;
    }
    return t;
}



bool matchTreeIterative(tree root,unsigned int *list,unsigned int size)
{
    bool status = false;
    
    // Write your code here.
    
    //note that it is not assumed that size of list is same as 
    //number of nodes in tree
    int i = 0;
    tree ptr = root;
    stack s = createStack();
    while(ptr != NULL){
    	if(i < size && ptr->data == list[i])
    		i++;
    	else
    		return status;
    	push(&s,ptr);
    	ptr = ptr->left;
    }
    while(!isEmpty(s)){
    	ptr = top(&s);
    	pop(&s);
    	ptr = ptr->right;
    	while(ptr != NULL){
    		if(i<size && ptr->data == list[i])
    			i++;
    		else
    			return status;
    		push(&s,ptr);
    		ptr = ptr->left;
    	}
    }
    if(i==size)
    	status = true;
    return status;


}
