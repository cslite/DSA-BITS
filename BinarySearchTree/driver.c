#include<stdio.h>
#include<stdlib.h>
#include"btree.h"

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("No input file!\n");
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if(fp==NULL){
		printf("Cannot open file!\n");
		return -1;
	}
	int sz;
	fscanf(fp,"%d",&sz);
	int *arr = (int *)(malloc(sizeof(int)*sz));
	for(int i=0;i<sz;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	btree bt = createTree(arr,sz);
	inOrderWalk(bt.root);
	printf("\n");
	preOrderWalk(bt.root);
	printf("\n");
	printf("min = %d\n",getMin(bt.root)->key);
	printf("max = %d\n",getMax(bt.root)->key);
	node *ptr = searchKey(bt.root,11);
	printf("searched_node = %d\n",ptr->key);
	printf("succ = %d\n",succ(ptr)->key);
	printf("pred = %d\n",pred(ptr)->key);
	ptr = searchKey(bt.root,11);
	deleteNode(&bt,ptr);
	inOrderWalk(bt.root);
	printf("\n");
	ptr = searchKey(bt.root,8);
	deleteNode(&bt,ptr);
	inOrderWalk(bt.root);
	printf("\n");
	ptr = searchKey(bt.root,6);
	deleteNode(&bt,ptr);
	inOrderWalk(bt.root);
	printf("\n");
	ptr = searchKey(bt.root,2);
	deleteNode(&bt,ptr);
	inOrderWalk(bt.root);
	printf("\n");
return 0;
}
