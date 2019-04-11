#include<stdio.h>
#include<stdlib.h>
#include"avl.h"

int main(int argc, char *argv[]){
	node *root = NULL;
	node *rootavl = NULL;
	// int t;
	// while(1){
	// 	scanf("%d",&t);
	// 	if(t==-1)
	// 		break;
	// 	root = add(root,t);
	// 	rootavl = add_avl(rootavl,t);
	// }
	// printTree(root,0);
	// printTree(rootavl,0);
	
	root = add(root, 5);
	root = add(root,9);
	root = add(root,6);
	root = add(root,21);
	root = add(root, 2);
	root = add(root, 3);
	root = add(root,1);
	root = add(root,4);
	root = add(root,8);
	root = add(root,15);
	printTree(root,0);


	node *avltree = NULL;
	avltree = add_avl(avltree,5);
	avltree = add_avl(avltree,9);
	avltree = add_avl(avltree,6);
	avltree = add_avl(avltree,21);
	avltree = add_avl(avltree,2);
	avltree = add_avl(avltree,3);
	avltree = add_avl(avltree,1);
	avltree = add_avl(avltree,4);
	avltree = add_avl(avltree,8);
	avltree = add_avl(avltree,15);
	printTree(avltree,0);	

	node *x = rankQuery(avltree,5);
	printf("rankQuery 1 : %d\n",x->key);

	// x = rankQuery(root,2);
	// printf("rankQuery 2 : %d\n",x->key);
	
	// x = rankQuery(root,3);
	// printf("rankQuery 3 : %d\n",x->key);
	
	rangeSet r1 = rangeQuery(avltree,2,6);
	printf("\n");
	for(int i=0;i<r1.size;i++){
		printf("%d\n",(r1.arr)[i]->key);
	}

	// root = delete(root,1);
	// printTree(root,0);
	// root = delete(root,5);
	// printTree(root,0);



return 0;
}
