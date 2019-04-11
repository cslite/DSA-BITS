#include<stdio.h>
#include<stdlib.h>
#include"avl.h"

#define PATH_MAX 100
#define RANGE_MAX 100
#define STACK_SIZE 50

//function to get height of a node
int height(node *x){
	if(x== NULL)
		return -1;
	else
		return x->h;
}

//normal BST add operation
node *add(node *root, int key){
	//only unique keys get added
	node *nn = (node *)(malloc(sizeof(node)));
	nn->key = key;
	nn->left = nn->right = NULL;
	nn->h = 0;
	nn->balance = 0;
	if(root == NULL){
		//tree is initially empty
		return nn;
	}
	node *ptr = root;
	while(ptr != NULL){
		if(key > ptr->key){
			//go to right subtree
			if(ptr->right != NULL)
				ptr=ptr->right;
			else{
				ptr->right = nn;
				return root;
			}
		}
		else if(key < ptr->key){
			//go to left subtree
			if(ptr->left != NULL)
				ptr = ptr->left;
			else{
				ptr->left = nn;
				return root;
			}
		}
		else
			return root;	//a duplicate key does not get inserted
	}
}

//to find a node in a BST
node *find(node *root, int key){
	if(root == NULL)
		return NULL;
	node *ptr = root;
	while(ptr != NULL){
		if(key == ptr->key){
			return ptr;
		}
		else if(key > ptr->key){
			ptr = ptr->right;
		}
		else{
			ptr = ptr->left;
		}
	}
	return NULL;	//key not found
}

//find miniumum of a node in a BST
node *find_min(node *root){
	if(root == NULL)
		return NULL;
	node *ptr = root;
	while(ptr->left != NULL){
		ptr = ptr->left;
	}
	return ptr;
}

//normal BST - delete operation
node *delete(node *root, int key){
	if(root == NULL)	return NULL;
	node *ptr = root;
	node *p = NULL;
	while(ptr != NULL){
		if(key == ptr->key)
			break;
		else if(key > ptr->key){
			p = ptr;
			ptr = ptr->right;
		}
		else{
			p = ptr;
			ptr = ptr->left;
		}
	}
	if(ptr == NULL){
		//key was not found
		return root;
	}
	else{
		//ptr is the node to be deleted
		if(ptr->left == NULL && ptr->right == NULL){
			//leaf node
			if(p == NULL){
				//ptr is the root node
				free(ptr);
				return NULL;
			}
			else if(p->left == ptr){
				p->left = NULL;
				free(ptr);
				return root;
			}
			else{
				p->right = NULL;
				free(ptr);
				return root;
			}
		}
		else if(ptr->left == NULL){
			//it has only right child
			if(p == NULL){
				//ptr is the root node
				node *t = ptr->right;
				free(ptr);
				return t;
			}	
			else if(p->left == ptr){
				p->left = ptr->right;
				free(ptr);
				return root;
			}
			else{
				p->right = ptr->right;
				free(ptr);
				return root;
			}
		}
		else if(ptr->right == NULL){
			if(p == NULL){
				node *t = ptr->left;
				free(ptr);
				return t;
			}
			else if(p->left == ptr){
				p->left = ptr->left;
				free(ptr);
				return root;
			}
			else{
				p->right = ptr->left;
				free(ptr);
				return root;
			}
		}
		else{
			//it has 2 children
			node *mnode = find_min(ptr->right);	//find successor of ptr
			ptr->key = mnode->key;
			ptr->right = delete(ptr->right,mnode->key);
			return root;	
			//this will also work when ptr is the root node
		}
		
	}
}

//helper function for rotate operation
void getabc(node *x, node *y, node *z, node **a, node **b, node**c){
	if(x->key < y->key){
		if(x->key < z->key){
			*a = x;
			if(y->key < z->key){
				*b = y;
				*c = z;
			}
			else{
				*b = z;
				*c = y;
			}
		}
		else{
			*b = x;
			*c = y;
			*a = z;
		}
	}
	else{
		if(x->key > z->key){
			//x>y && x>z
			*c = x;
			if(y->key > z->key){
				*b = y;
				*a = z;
			}
			else{
				*b = z;
				*a = y;
			}
		}
		else{
			//x<z && x>y
			*a = y;
			*b = x;
			*c = z;
		}
	}
}

//helper function for rotate operation
int not_abc(node *a, node *b, node *c, node *ptr){
	if(ptr != a && ptr != b && ptr != c)
		return 1;
	else
		return 0;
}

//helper function for rotate operation
void getTs(node *a, node *b, node *c, node *t[]){
	int i = 0;
	if(not_abc(a,b,c,a->left))
		t[i++] = a->left;
	if(not_abc(a,b,c,a->right))
		t[i++] = a->right;
	if(not_abc(a,b,c,b->left))
		t[i++] = b->left;
	if(not_abc(a,b,c,b->right))
		t[i++] = b->right;
	if(not_abc(a,b,c,c->left))
		t[i++] = c->left;
	if(not_abc(a,b,c,c->right))
		t[i++] = c->right;
	//assert that i is equal to 4
	if(i != 4)
		printf("Some Error at getTs!\n");
}

//to update height & balance factor of a node
void updateHeight(node *x, node *l, node *r){
	//x is the node
	//l is the left child and r is the right child
	int htmp=0;

	if(l != NULL)
		htmp += l->h;
	if(htmp > x->h)
		x->h = htmp;
	htmp = 0;
	if(r != NULL)
		htmp += r->h;
	if(htmp > x->h)
		x->h = htmp;
	int bal = height(r) - height(l);
	switch(bal){
		case 1:
			x->balance = 1;
			break;
		case -1:
			x->balance = -1;
			break;
		case 0:
			x->balance = 0;
			break;
		default:
			printf("There is some error! The tree is not avl balanced!\n");

	}	
}

//generalized rotate operation
node *rotate(node *root, node* x, node *y, node *z, node *zp){
	if(root == NULL || x == NULL || y == NULL || z == NULL)
		return NULL;
	//z is the first unbalanced node along the path from inserted node to root
	//y is child of z, x is child of y
	node *a,*b,*c;
	//a, b and c are left to right listing of nodes
	getabc(x,y,z,&a,&b,&c);
	
	node *t[4];
	getTs(a,b,c,t);
	
	//replacing z with b
	if(zp == NULL){
		root = b;
	}
	else{
		if(zp->left == z)
			zp->left = b;
		else
			zp->right = b;
	}
	
	updateHeight(a,t[0],t[1]);

	//setting t0 and t1 as the left and right children of a
	a->left = t[0];
	a->right = t[1];

	updateHeight(c,t[2],t[3]);

	//setting t2 and t3 as the left and right children of c
	c->left = t[2];
	c->right = t[3];

	
	updateHeight(b,a,c);

	//setting a and c as the left and right children of b
	b->left = a;
	b->right = c;
	
	return root;

}

//Add node operation for AVL Trees
node *add_avl(node *root, int key){
	//only unique keys get added
	node *nn = (node *)(malloc(sizeof(node)));
	nn->key = key;
	nn->left = nn->right = NULL;
	nn->h = 0;
	nn->balance = 0;
	if(root == NULL){
		//tree is initially empty
		return nn;
	}
	node *ptr = root;
	node *stack[STACK_SIZE];
	char needsBalancing = 0;
	int si = 0;
	int i = 0;
	while(ptr != NULL){
		stack[si++] = ptr;
		if(key > ptr->key){
			//go to right subtree
			if(ptr->balance == 1){
				needsBalancing = 1;
			}
			if(ptr->right != NULL)
				ptr=ptr->right;
			else{
				ptr->right = nn;
				break;
				// return root;
			}
		}
		else if(key < ptr->key){
			//go to left subtree
			if(ptr->balance == -1)
				needsBalancing = 1;
			if(ptr->left != NULL)
				ptr = ptr->left;
			else{
				ptr->left = nn;
				break;
				// return root;
			}
		}
		else
			return root;
	}
	stack[si] = nn;
	if(needsBalancing){
		for(i=(si-1);i>=0;i--){
			if(stack[i]->balance == -1 || stack[i]->balance == 1)
			{
				if(i-1 >= 0)
					root = rotate(root,stack[i+2],stack[i+1],stack[i],stack[i-1]);
				else
					root = rotate(root,stack[i+2],stack[i+1],stack[i],NULL);
				return root;
			}
		}
	}
	else{
		if(stack[si-1]->left == nn)
			stack[si-1]->balance--;
		else
			stack[si-1]->balance++;
		for(i=(si-2);i>=0;i--){
			if(stack[i]->left == stack[i+1])
				stack[i]->balance--;
			else
				stack[i]->balance++;
		}
		return root;
	}		
			 
}

//INCOMPLETE
node *delete_avl(node *root, int key){
	if(root == NULL)	return NULL;
	node *ptr = root;
	node *p = NULL;
	while(ptr != NULL){
		if(key == ptr->key)
			break;
		else if(key > ptr->key){
			p = ptr;
			ptr = ptr->right;
		}
		else{
			p = ptr;
			ptr = ptr->left;
		}
	}
	if(ptr == NULL){
		//key was not found
		return root;
	}
	else{
		//ptr is the node to be deleted
		if(ptr->left == NULL && ptr->right == NULL){
			//leaf node
			if(p == NULL){
				//ptr is the root node
				free(ptr);
				return NULL;
			}
			else if(p->left == ptr){
				p->left = NULL;
				free(ptr);
				return root;
			}
			else{
				p->right = NULL;
				free(ptr);
				return root;
			}
		}
		else if(ptr->left == NULL){
			//it has only right child
			if(p == NULL){
				//ptr is the root node
				node *t = ptr->right;
				free(ptr);
				return t;
			}	
			else if(p->left == ptr){
				p->left = ptr->right;
				free(ptr);
				return root;
			}
			else{
				p->right = ptr->right;
				free(ptr);
				return root;
			}
		}
		else if(ptr->right == NULL){
			if(p == NULL){
				node *t = ptr->left;
				free(ptr);
				return t;
			}
			else if(p->left == ptr){
				p->left = ptr->left;
				free(ptr);
				return root;
			}
			else{
				p->right = ptr->left;
				free(ptr);
				return root;
			}
		}
		else{
			//it has 2 children
			node *mnode = find_min(ptr->right);	//find successor of ptr
			ptr->key = mnode->key;
			ptr->right = delete(ptr->right,mnode->key);
			return root;	
			//this will also work when ptr is the root node
		}
		
	}
}

//returns the Kth smallest element in BST by inorder traversal
node *rankQuery(node *root, int k){
	node *path[PATH_MAX];
	int i = 0;
	if(root == NULL)
		return NULL;
	node *ptr = root;
	int cnt = 0;
	ptr = root;
	while(ptr != NULL){
		path[++i] = ptr;
		// printf("1..pushing..%d\n",ptr->key);
		ptr = ptr->left;
	}
	while(i){
		ptr = path[i--];
		// printf("0..popping..%d\n",ptr->key);
		// printf("%d ->",ptr->key);
		cnt++;
		if(cnt == k){
			// printf("\n");
			return ptr;
		}
		ptr = ptr->right;
		while(ptr != NULL){
			path[++i] = ptr;
			// printf("2..pushing..%d\n",ptr->key);
			ptr = ptr->left;
		}
	}
	// printf("\n");
	return NULL;
}

//helper function for rangeQuery
int rq(node *root, int k1, int k2, node *arr[], int i){
	if(root == NULL)
		return i;
	if(root->key > k2){
		return rq(root->left, k1, k2, arr, i);
	}
	if(root->key < k1)
		return rq(root->right, k1, k2, arr, i);
	if(k1 <= root->key && root->key <= k2){
		i = rq(root->left, k1, root->key, arr, i);
		arr[i++] = root;
		return rq(root->right, root->key, k2, arr, i);
	}
}

//find nodes in the bst which have key values in the range [k1,k2]
rangeSet rangeQuery(node *root, int k1, int k2){
	node **arr = (node **)(malloc(sizeof(node *) * RANGE_MAX));
	int size = rq(root, k1, k2, arr, 0);
	rangeSet r1 = {arr,size};
	return r1;
}
		
					
//TAKEN FROM STACKOVERFLOW for PRINTING THE BST
int rec[1000006];
void printTree(node* curr,int depth)
{
    int i;
    if(curr==NULL)return;
    printf("\t");
    for(i=0;i<depth;i++)
        if(i==depth-1)
            printf("%s\u2014\u2014\u2014",rec[depth-1]?"\u0371":"\u221F");
        else
            printf("%s   ",rec[i]?"\u23B8":"  ");
    printf("%d\n",curr->key);
    rec[depth]=1;
    printTree(curr->left,depth+1);
    rec[depth]=0;
    printTree(curr->right,depth+1);
}	
