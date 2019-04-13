#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trie.h"

int main(){
	node *trie = NULL;
	int ch;
	char str[200];
	do{
		scanf("%d",&ch);
		switch(ch){
			case 0:
				getchar();
				fgets(str,199,stdin);
				trie = createTrie(str);
				break;
			case 1:
				printTrie(trie);
				break;
			case 2:
				scanf("%s",str);
				printf("%d\n",find(trie,str));
				break;
			case 3:
				break;
			case -1:
				break;
		}
	}while(ch != -1);
return 0;
}
