#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

node *searchKey(node *root, int key){
	if(root == NULL)
		return NULL;
	if(root->key == key)
		return root;
	if(key < root->key)
		return searchKey(root->left, key);
	else
		return searchKey(root->right,key);
	//ensure that nodes with same key value get stored on the right side
}
