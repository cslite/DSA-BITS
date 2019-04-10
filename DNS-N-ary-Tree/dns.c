#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dns.h"

#define LEN_MAX 25
#define PATH_MAX 30

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
	while(l>=0 && l<=r){
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

node *insert_new_child(node *ptr, char *sd){
	
	int i,j;
	int noc = ptr->noc;
	if(noc == 0){
		(ptr->child)[0] = create_node();
		(ptr->child)[0]->key = sd;
		ptr->noc ++;
		return (ptr->child)[0];
	}
	if(ptr->noc + 1 == ptr->sz){
		// we need to extend the child array
		ptr->sz *= 2;
		ptr->child = (node **)(realloc(ptr->child,sizeof(node *)*(ptr->sz)));
	}
	node **child = ptr->child;
	if(strcmp(sd,child[0]->key) < 0){
		//sd is smaller than the first key
		for(j=noc-1; j>=0; j--)
			child[j+1] = child[j];
		child[0] = create_node();
		child[0]->key = sd;
		ptr->noc ++;
		return child[0];
	}
	else if(strcmp(sd,child[noc - 1]->key) > 0){
		//sd is even bigger than the last key
		child[noc] = create_node();
		child[noc]->key = sd;
		ptr->noc ++;
		return child[noc];
	}
	for(i=0;i<(ptr->noc - 1); i++){
		if(strcmp(child[i]->key,sd) < 0 && strcmp(child[i+1]->key, sd) > 0){
			//we need to insert here
			for(j=noc-1;j>i;j--)
				child[j+1] = child[j];
			child[i+1] = create_node();
			child[i+1]->key = sd;
			ptr->noc ++;
			return child[i+1];
		}
	}
}

sdarr generate_sd(char *url){
	char **sd = (char **)(malloc(sizeof(char *)*30));
	char u1[LEN_MAX];
	char u2[LEN_MAX];
	char *pu1;
	char dl[2] = ".";
	int i = 0;
	char *token;
	token = strtok(url,dl);
	while(token != NULL){
		pu1 = (char *)(malloc(sizeof(char)*(strlen(token) + 1)));
		strcpy(pu1,token);
		sd[i++] = pu1;
		token = strtok(NULL,dl);
	}
	/*
	while(sscanf(url,"%s.%s",u1,u2) == 2){
		pu1 = (char *)(malloc(sizeof(char)*(strlen(u1) + 1)));
		strcpy(pu1,u1);
		sd[i++] = pu1;
		url = (char *)(malloc(sizeof(char)*(strlen(u2) + 1)));
		strcpy(url,u2);
	}
	sd[i++] = url;
	*/
	//now subdomains array contain all the parts of the url	
	sdarr s = {sd,i};
	return	s;
}

void insert(node *root, char *url, char *ip){
	if(root == NULL){
		printf("Invalid Tree!\n");
		return;
	}
	sdarr s = generate_sd(url);
	int i = s.sz;
	char **subdomains = s.sd;
	//now subdomains array contain all the parts of the url
	int j,idx;
	node *ptr = root;
	node *t = NULL;
	for(j=i-1;j>=0;j--){
		idx = search(ptr,subdomains[j]);
		if(idx == -1){
			//we need to insert this new subdomain
			ptr = insert_new_child(ptr,subdomains[j]);
		}
		else
			ptr = (ptr->child)[idx];
	}
	//now ptr is at the last node in the path
	insert_new_child(ptr,ip);
} 
		
void readData(node *root, int n){
	/*
	if(fp == NULL){
		printf("Cannot read file!\n");
		return;
	}
	*/
	if(root == NULL){
		printf("Invalid Tree\n");
		return;
	}
	int i;
	char t_url[LEN_MAX];
	char t_ip[20];
	char *url;
	char *ip;
	for(i=0;i<n;i++){
		scanf("%s%s",t_url,t_ip);
		url = (char *)(malloc(sizeof(char)*(strlen(t_url)+1)));
		strcpy(url,t_url);
		ip = (char *)(malloc(sizeof(char)*20));
		strcpy(ip,t_ip);
		insert(root,url,ip);
	}
}

void lookup(node *root, char *name){
	if(root == NULL)
		return;
	sdarr s = generate_sd(name);	//to get all subdomains of the given domain name
	int path[PATH_MAX] = {0};
	int pi = 0;
	node *ptr = root;
	int i,idx;
	for(i=(s.sz - 1);i>=0;i--){
		idx = search(ptr,s.sd[i]);
		if(idx == -1)
			break;
		else
			path[pi++] = idx;
		ptr = (ptr->child)[idx];
	}
	if(pi < s.sz){
		//it was not found
		for(i=0;i<pi;i++)
			printf("%d ",path[i]);
		printf("\n");
		return;
	}
	else{
		int noc = ptr->noc;
		for(i=0;i<noc;i++){
			printf("%s\n",(ptr->child)[i]->key);
		}
		return;
	}
}
			
		
