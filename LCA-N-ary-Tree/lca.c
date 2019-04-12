#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lca.h"

#define LEN_MAX 25
#define PATH_MAX 30
#define DEPTH_MAX 30

node *create_node(){
	node *n = (node *)(malloc(sizeof(node)));
	n->key = NULL;
	n->noc = 0;
	n->child = (node **)(malloc(sizeof(node *)*5));
	n->sz = 5;
	return n;
}

int search(node *ptr, char *str){
	//it will return the index of the child with key same as str
	node **child = ptr->child;
	int l,r,mid,cmp;
	if(ptr->noc == 0)
		return -1;
	l = 0;
	r = (ptr->noc) - 1;
	while(l<=r){
		mid = l + (r-l)/2;
		cmp = strcmp(child[mid]->key,str);
		if(cmp == 0){
			//we found the index
			return mid;
		}
		else if(cmp < 0){
			//it means that key at child[mid] is smaller than str
			l = mid +1;
		}
		else{
			r = mid -1;
		}
	}
	return -1;	//key not found
}

node *insert_new_child(node *ptr, char *sp){
	
	int i,j;
	int noc = ptr->noc;
	if(noc == 0){
		(ptr->child)[0] = create_node();
		(ptr->child)[0]->key = sp;
		ptr->noc ++;
		return (ptr->child)[0];
	}
	if(ptr->noc + 1 == ptr->sz){
		// we need to extend the child array
		ptr->sz *= 2;
		ptr->child = (node **)(realloc(ptr->child,sizeof(node *)*(ptr->sz)));
	}
	node **child = ptr->child;
	if(strcmp(sp,child[0]->key) < 0){
		//sp is smaller than the first key
		for(j=noc-1; j>=0; j--)
			child[j+1] = child[j];
		child[0] = create_node();
		child[0]->key = sp;
		ptr->noc ++;
		return child[0];
	}
	else if(strcmp(sp,child[noc - 1]->key) > 0){
		//sd is even bigger than the last key
		child[noc] = create_node();
		child[noc]->key = sp;
		ptr->noc ++;
		return child[noc];
	}
	for(i=0;i<(ptr->noc - 1); i++){
		if(strcmp(child[i]->key,sp) < 0 && strcmp(child[i+1]->key, sp) > 0){
			//we need to insert here
			for(j=noc-1;j>i;j--)
				child[j+1] = child[j];
			child[i+1] = create_node();
			child[i+1]->key = sp;
			ptr->noc ++;
			return child[i+1];
		}
	}
}

pathArr generate_pathArr(char *path){
	char **p = (char **)(malloc(sizeof(char *)*DEPTH_MAX));
	path = path+1;	//to start from the first
	char *token = strtok(path,"/");
	int pi = 0;
	while(token != NULL){
		p[pi++] = token;
		token = strtok(NULL,"/");
	}
	pathArr parr = {p,pi};
	// printf("i sent pi=%d\n",pi);
	return parr;
}


void insert(node *root, char *path){
	if(root == NULL){
		printf("Invalid Tree!\n");
		return;
	}
	pathArr p1 = generate_pathArr(path);
	node *ptr = root;
	int i;
	for(i=0;i<p1.sz;i++){
		int idx = search(ptr,p1.p[i]);
		if(idx == -1){
			//it was not found
			ptr = insert_new_child(ptr,p1.p[i]);
		}
		else{
			ptr = (ptr->child)[idx];
		}
	}
}

void readData(node *root, int n){
	// printf("data reading started\n");
	if(root == NULL){
		printf("Invalid Tree\n");
		return;
	}
	int i;
	char ptmp[LEN_MAX];
	char *path;
	getchar();
	for(i=0;i<n;i++){
		fgets(ptmp,LEN_MAX-1,stdin);
		// printf("%s\n\n",ptmp);
		int ln = strlen(ptmp)-1;
		if(ptmp[ln] == '\n')
			ptmp[ln] = '\0';	//to remove the new line character
		path = (char *)(malloc(sizeof(char)*(ln+1)));
		strcpy(path,ptmp);
		insert(root,path);
	}
	// printf("data reading done\n");
}

void find_lca(node *root, char *p1, char *p2){
	int indx[PATH_MAX];
	pathArr pa1 = generate_pathArr(p1);
	pathArr pa2 = generate_pathArr(p2);
	int i=0,x=0;
	node *ptr = root;
	int notFound = 0;
	while(i<pa1.sz && i <pa2.sz){
		if(strcmp(pa1.p[i],pa2.p[i]) == 0){
			// printf("f1\n");
			int cidx = search(ptr,pa1.p[i]);
			if(cidx == -1){
				// printf("f12\n");
				printf("%s\n",pa1.p[i]);
				notFound = 1;
				break;
			}
			else{
				// printf("f13\n");
				indx[x++] = cidx+1;
				ptr = (ptr->child)[cidx];
			}
		}
		else
			break;
		// printf("f3\n");
		i++;
	}
	if(x == 0){
		printf("0\n");
	}
	else if(notFound){
		printf("No such path exists in the dir!\n");
	}
	else{
		for(int k=0;k<x;k++)
			printf("%d ",indx[k]);
		printf("\n");
	}
}
