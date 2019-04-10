#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dns.h"

//int main(int argc, char *argv[]){
int main(){
	/*
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Cannot open file!\n");
		return -1;
	}
	*/
	int ch;
	int n;
	char str[30];
	node *tree = create_node();
	do{
		scanf("%d",&ch);
		switch(ch){
			case 1:
				scanf("%d",&n);
				readData(tree,n);
				break;
			case 2:
				scanf("%s",str);
				lookup(tree,str);
				break;
			case -1:
				break;
			default:
				break;
		}
	}while(ch != -1);
return 0;
}
