#include<stdio.h>
#include<stdlib.h>
#include "card.h"
#include<string.h>

cardinfo genci(char *str){
	//it will be given a string wiht all info for a record
	cardinfo ci;
	int i = 0;
	if(str[i] == '"')
		i++;
	else{
		printf("Wrong format string!\n");
		return ci;
	}
	int c = 0;
	while(str[i] != ','){
		ci.cno[c++] = str[i++];
	}
	ci.cno[c]  = '\0';
	i++;
	c = 0;
	while(str[i] != ','){
		ci.bankcode[c++] = str[i++];
	}
	ci.bankcode[c] = 0;
	i++;
	char my[5];
	c = 0;
	while(str[i] != '/'){
		my[c++] = str[i++];
	}
	my[c] = '\0';
	ci.exp_m = atoi(my);
	i++;
	c=0;
	while(str[i] != ','){
		my[c++] = str[i++];
	}
	my[c] = 0;
	ci.exp_y = atoi(my);
	i++;
	c=0;
	while(str[i] != ','){
		ci.fname[c++] = str[i++];
	}
	ci.fname[c] = 0;
	i++;	c=0;
	while(str[i] != '"'){
		ci.lname[c++] = str[i++];
	}
	ci.lname[c] = 0;
	return ci;
}
