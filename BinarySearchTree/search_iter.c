#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

//Search is O(lgN) or O(h) where n is the number of nodes and h is the height of the tree
node *searchKey(node *root, int key){
	if(root == NULL)
		return NULL;
	node *curr = root;
	while(curr!=NULL){
		if(key == curr->key)
			return curr;
		else if(key < curr->key){
			curr = curr->left;
		}
		else{
			curr = curr->right;
		}
	}
	return NULL;
}
