#include<stdio.h>
#include<stdlib.h>
#include "card.h"
#include<string.h>

cardinfo genci(char *str){
	//it will be given a string with all info for a record
	cardinfo ci;
	sscanf(str,"\"%[^,],%[^,],%d/%d,%[^,],%[^\"]",ci.cno,ci.bankcode,&ci.exp_m,&ci.exp_y,ci.fname,ci.lname);
	// printf("TEST:\n%s\n%s\n%d/%d\n%s\n%s\n",ci.cno,ci.bankcode,ci.exp_m,ci.exp_y,ci.fname,ci.lname);
	return ci;
}
