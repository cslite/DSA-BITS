#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashtable.h"

int main(){
	int ch,nk;
	ht *htables = NULL;
	do{
		scanf("%d",&ch);
		switch(ch){
			case 1:
				scanf("%d",&nk);
				htables = readRecords(nk);
				break;
			case 2:
				scanf("%d",&nk);
				readQueries(nk,htables);
				break;
			case 3:
				findInsertionComplexity(htables);
				break;
			case 4:
				findQueryComplexity(htables);
				break;
			case -1:
				break;

		}
	}while(ch != -1);
return 0;
}
