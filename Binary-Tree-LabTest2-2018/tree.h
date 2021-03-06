/******************************************************
*           DSA Lab Test 2: Problem 1 (tree.h)
*   
*               Do not edit this file.
* ****************************************************/
#include <stdbool.h>

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct _tnode
{
    unsigned int data;
    struct _tnode *left, *right;
};

typedef struct _tnode *tree;
enum probability {LEMPTY, REMPTY, NONEMPTY};

unsigned int* createList(unsigned int p);
tree constructTree(unsigned int *list, unsigned int len);
bool matchTreeIterative(tree root, unsigned int *x, unsigned int size);

#endif // TREE_H_INCLUDED
