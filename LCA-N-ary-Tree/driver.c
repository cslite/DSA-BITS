#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lca.h"

#define PATH_LEN_MAX 40

int main(){
	int ch;
	int n;
	char p1[PATH_LEN_MAX], p2[PATH_LEN_MAX];
	node *tree = create_node();
	do{
		scanf("%d",&ch);
		switch(ch){
			case 1:
				scanf("%d",&n);
				readData(tree,n);
				break;
			case 2:
				getchar();
				fgets(p1,PATH_LEN_MAX,stdin);
				p1[strlen(p1) - 1] = '\0';
				fgets(p2,PATH_LEN_MAX,stdin);
				p2[strlen(p2) - 1] = '\0';
				find_lca(tree,p1,p2);
				break;
			case -1:
				break;
			default:
				break;
		}
	}while(ch != -1);
return 0;
}
