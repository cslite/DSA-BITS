#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trie.h"

#define STACK_MAX 100

node *newNode(){
	node *ptr = (node *)(malloc(sizeof(node)));
	ptr->next = (node **)(calloc(sizeof(node *),4));
	return ptr;
}

enum dna getval(char c){
	switch(c){
		case 'A':
			return A;
		case 'C':
			return C;
		case 'G':
			return G;
		case 'T':
			return T;
	}
}

char getChar(int i){
	switch(i){
		case 0:
			return 'A';
		case 1:
			return 'C';
		case 2:
			return 'G';
		case 3:
			return 'T';
		
	}
}

void insert(node *root, char *seq){
	if(root == NULL)
		return;
	
	int i;
	node *ptr = root;
	for(i=0;i<4;i++){
		if((ptr->next)[getval(seq[i])] == NULL){
			(ptr->next)[getval(seq[i])] = newNode();
			ptr = (ptr->next)[getval(seq[i])];
		}
		else{
			ptr = (ptr->next)[getval(seq[i])];
		}
	}
	
}


node *createTrie(char *seq){
	node *root = newNode();
	char stopword[] = "X";
	char tseq[5];
	while(sscanf(seq,"%s",tseq) == 1){
		if(strcmp(tseq,stopword)==0)
			return root;
		insert(root,tseq);
		seq = seq + 5;
	}
	return root;
}


char pstr[5];
void print_Trie(node *root, int level){
	int i;
	if(level == 3)
	{
		printf("%s\t",pstr);
		return;
	}
	for(i=0;i<4;i++){
		if((root->next)[i] != NULL){
			pstr[level+1] = getChar(i);
			print_Trie((root->next)[i],level+1);
		}
	}
}


void printTrie(node *root){
	pstr[4] = '\0';
	printf("\n");
	print_Trie(root,-1);
	printf("\n");
}


int find(node *root, char *str){
	int i;
	node *ptr = root;
	for(i=0;i<4;i++){
		if((ptr->next)[getval(str[i])] != NULL)
			ptr = (ptr->next)[getval(str[i])];
		else
			return -1;
	}
	return 1;
}


