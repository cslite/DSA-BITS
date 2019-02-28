#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

void inOrderWalk(node *root){
	if(root != NULL){
		inOrderWalk(root->left);
		printf("%d ",root->key);
		inOrderWalk(root->right);
	}
}

void preOrderWalk(node *root){
	if(root!=NULL){
		printf("%d ",root->key);
		preOrderWalk(root->left);
		preOrderWalk(root->right);
	}
}

void postOrderWalk(node *root){
	if(root != NULL){
		postOrderWalk(root->left);
		postOrderWalk(root->right);
		printf("%d ",root->key);
	}
}

//complexity is O(lgN)
node *getMin(node *root){
	if(root == NULL)	return NULL;
	node *curr = root;
	while(curr->left != NULL)
		curr = curr->left;
	return curr;
}

//complexity is O(lgN)
node *getMax(node *root){
	if(root == NULL)	return NULL;
	node *curr = root;
	while(curr->right != NULL)
		curr = curr->right;
	return curr;
}


node *succ(node *ptr){
	if(ptr==NULL)	return NULL;
	if(ptr->right != NULL){
		return getMin(ptr->right);
	}
	else{
		while(ptr != NULL){
			if(ptr->parent != NULL && ptr->parent->left == ptr)
				return ptr->parent;
			ptr = ptr->parent;
		}
		return ptr;
	}
}

node *pred(node *ptr){
	if(ptr == NULL) return NULL;
	if(ptr->left != NULL)
		return getMax(ptr->left);
	else{
		while(ptr!=NULL){
			if(ptr->parent != NULL && ptr->parent->right == ptr)
				return ptr->parent;
			ptr = ptr->parent;
		}
		return ptr;
	}
}

node *createNode(int key){
	node *t = (node *)(malloc(sizeof(node)));
	t->key = key;
	t->left = t->right = t->parent = NULL;
	return t;
}

void insertNode(btree *bt, node *n){
	if(bt== NULL || n == NULL)
		return;
	if(bt->size == 0){
		bt->root = n;
		bt->size++;
	}
	else{
		node *ptr = bt->root;
		bt->size++;
		while(1){
			if(n->key >= ptr->key){
				if(ptr->right == NULL){
					ptr->right = n;
					n->parent = ptr;
					return;
				}
				else
					ptr = ptr->right;
			}
			else{
				if(ptr->left == NULL){
					ptr->left = n;
					n->parent = ptr;
					return;
				}
				else
					ptr = ptr->left;
			}
		}
	}
}

btree createTree(int *arr, int sz){
	btree bt = {NULL,0};
	// printf("createTree\n");
	for(int i=0;i<sz;i++){
		insertNode(&bt,createNode(arr[i]));
		// printf("done Insertion..%d\n",i);
	}
	return bt;
}

node *deleteNode(btree *bt, node *n){
	//case 1: leaf node
	if(n->left == NULL && n->right == NULL){
		if(n->parent == NULL){
			bt->root = NULL;
			bt->size = 0;
			return n;
		}
		else if(n->parent->left == n){
			n->parent->left = NULL;
		}
		else{
			n->parent->right = NULL;
		}
		(bt->size)--;
		return n;
	}
	//case 3: both child
	else if(n->left != NULL && n->right != NULL){
		node *repl = deleteNode(bt,succ(n));
		// printf("%d\n",repl->key);
		// inOrderWalk(bt->root);
		repl->left = n->left;
		if(n->left != NULL)
			n->left->parent = repl;
		repl->right = n->right;
		if(n->right != NULL)
			n->right->parent = repl;
		repl->parent = n->parent;
		bt->size--;
		if(n->parent == NULL){
			bt->root = repl;
		}
		else if(n->parent->left == n)
			n->parent->left = repl;
		else
			n->parent->right = repl;
		return n;
	}
	//case 2: one child
	else{
		node *kid = n->left == NULL ? n->right : n->left;
		if(n->parent == NULL)	//n was the root node
		{
			bt->root = kid;
		}
		else if(n->parent->left == n){
			n->parent->left = kid;
		}	
		else{
			n->parent->right = kid;
		}
		kid->parent = n->parent;
		bt->size--;
		return n;
	}
}
