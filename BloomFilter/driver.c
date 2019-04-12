#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"bf.h"

int main(int argc, char *argv[]){
	BloomFilter b = createBF(200);
	if(argc == 2){
		insertData(b,argv[1]);
	}
	int ch;
	char str[40];
	do{
		scanf("%d",&ch);
		switch(ch){
			case 1:
				scanf("%s",str);
				add(b,str);
				break;
			case 2:
				scanf("%s",str);
				check(b,str) ? printf("It may exist!\n") : printf("It does not exist!\n");
				break;
			default:
				break;

		}
	}while(ch==1 || ch==2);

return 0;

}
