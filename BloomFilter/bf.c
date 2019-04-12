#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"bf.h"

#define NUM_HASH_FUNS 4

BloomFilter createBF(int size){
	BloomFilter b1;
	b1.bf = (char *)(calloc(sizeof(char),size));
	b1.size = size;
	return b1;
}


int hashval(char *str, int option, int tsz){
	int hashfuns[] = {211,149,157,117};
	int i = 0;
	int mul = 1;
	int hv = 0;
	while(str[i] != '\0'){
		hv += ((str[i++])*mul)%hashfuns[option];
		mul *= 10;
		mul %= hashfuns[option];
	}
	return ((hv)%tsz);
}


void add(BloomFilter b, char *str){
	int op;
	for(op=0;op<NUM_HASH_FUNS;op++){
		b.bf[hashval(str,op,b.size)] = 1;
	}
}


bool check(BloomFilter b, char *str){
	int op;
	for(op=0;op<NUM_HASH_FUNS;op++){
		if(b.bf[hashval(str,op,b.size)] == 0)
			return false;
	}
	return true;
}


void insertData(BloomFilter b, char *filename){
	if(filename == NULL)
		return;
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
		return;
	int cnt;
	fscanf(fp,"%d",&cnt);
	char str[40];
	while(fscanf(fp,"%s",str) == 1){
		add(b,str);
	}
}
