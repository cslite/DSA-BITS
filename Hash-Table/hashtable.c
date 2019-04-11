#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashtable.h"

int hashfun(student *s, int option){
	int i,idx,tablelength;
	switch(option){
		case 1:
			tablelength = 20;
			idx = 0;
			for(i=0;i<8;i++)
				idx += (s->name)[i];
			idx = (idx%89)%tablelength;
			break;
		case 2:
			tablelength = 20;
			idx = 0;
			for(i=0;i<8;i++)
				idx += (s->name)[i];
			idx = (idx%105943)%tablelength;
			break;
		case 3:
			tablelength = 200;
			idx = 0;
			for(i=0;i<8;i++)
				idx += (s->name)[i];
			idx = (idx%89)%tablelength;
			break;
		case 4:
			tablelength = 200;
			idx = 0;
			for(i=0;i<8;i++)
				idx += (s->name)[i];
			idx = (idx%105943)%tablelength;
			break;
		case 5:
			tablelength = 20;
			idx = ((s->id)%89)%tablelength;
			break;
		case 6:
			tablelength = 20;
			idx = ((s->id)%105943)%tablelength;
			break;
		case 7:
			tablelength = 200;
			idx = ((s->id)%89)%tablelength;
			break;
		case 8:
			tablelength = 200;
			idx = ((s->id)%105943)%tablelength;
			break;
	}
	return idx;
}

ht createHT(int size){
	ht t1;
	t1.arr = (node *)(calloc(sizeof(node),size));
	t1.tableLength = size;
	t1.elementCount = 0;
	t1.loadFactor = 0;
	t1.insertionTime = 0;
	t1.queryingTime = 0;
	return t1; 
}

void updateLF(ht *t){
	t->loadFactor = (float)(t->elementCount) / (t->tableLength);
}

void insert(ht *t, student *s, int hashval){
	node *arr = t->arr;
	if(arr[hashval].s == NULL){
		//there is no student present at this hash value
		arr[hashval].s = s;
		t->elementCount ++;
	}
	else{
		node *ptr = &(arr[hashval]);
		while(ptr->next != NULL){
			t->insertionTime ++;
			ptr = ptr->next;
		}
		ptr->next = (node *)malloc(sizeof(node));
		ptr = ptr->next;
		t->insertionTime ++;
		ptr->s = s;
		ptr->next = NULL;
	}
	updateLF(t);
}

ht *readRecords(int numRecords){
	int i;
	char name[9];
	long id;
	records = (student *)(malloc(sizeof(student)*numRecords));
	for(i=0;i<numRecords;i++){
		scanf("%s%ld",name,&id);
		records[i].id = id;
		strcpy(records[i].name,name);
	}
	ht *htables = (ht *)(malloc(sizeof(ht)*8));

	htables[0] = createHT(20);
	htables[1] = createHT(20);
	htables[2] = createHT(200);
	htables[3] = createHT(200);
	htables[4] = createHT(20);
	htables[5] = createHT(20);
	htables[6] = createHT(200);
	htables[7] = createHT(200);

	for(i=0;i<numRecords;i++){
		for(int op = 0; op<8;op++){
			int hashval = hashfun(records+i,op+1);
			insert(htables+op,records+i,hashval);
		}
	}

	return htables;
}

node *find(ht *t, student *stmp, int option){
	int hashval = hashfun(stmp,option);
	if((t->arr)[hashval].s == NULL){
		t->queryingTime++;
		return NULL;
	}
	else{
		node *ptr = &((t->arr)[hashval]);
		while(ptr != NULL){
			t->queryingTime++;
			if(strcmp(ptr->s->name,stmp->name) == 0 && ptr->s->id == stmp->id){
				return ptr;
			}
			else
				ptr = ptr->next;
			
		}
		return NULL;
	}
}

void readQueries(int numQueries, ht *arr){
	if(arr == NULL){
		printf("You need hashTables before querying!\n");
		return;
	}
	int i,op;
	student stmp;
	// char name[9];
	// long id;
	for(op=0;op<8;op++)
		arr[op].queryingTime = 0;
	for(i=0;i<numQueries;i++){
		scanf("%s%ld",stmp.name,&stmp.id);
		for(op=0;op<8;op++){
			
			// student stmp = (student){name,id};
			find(arr+op,&stmp,op+1);
		}
	}
}

void findInsertionComplexity(ht *arr){
	if(arr == NULL){
		printf("You need hashTables before using this!\n");
		return;
	}
	int ic[8];
	int op[8];
	int i;
	for(i=0;i<8;i++){
		ic[i] = arr[i].insertionTime;
		op[i] = i+1; 
	}
	//insertion sort for insertionTimes
	int j,tmp_ic,tmp_op;
	for(i=1;i<8;i++){
		tmp_ic = ic[i];
		tmp_op = op[i];
		for(j=i-1;j>=0;j--){
			if(ic[j] > tmp_ic){
				ic[j+1] = ic[j];
				op[j+1] = op[j];
			}
			else{
				break;
			}
		}
		ic[j+1] = tmp_ic;
		op[j+1] = tmp_op;
	}
	for(i=0;i<8;i++){
		printf("%d\t%d\n",op[i],ic[i]);
	}
}


void findQueryComplexity(ht *arr){
	if(arr == NULL){
		printf("You need hashTables before using this!\n");
		return;
	}
	int qc[8];
	int op[8];
	int i;
	for(i=0;i<8;i++){
		qc[i] = arr[i].queryingTime;
		op[i] = i+1; 
	}
	//insertion sort for queryingTimes
	int j,tmp_qc,tmp_op;
	for(i=1;i<8;i++){
		tmp_qc = qc[i];
		tmp_op = op[i];
		for(j=i-1;j>=0;j--){
			if(qc[j] > tmp_qc){
				qc[j+1] = qc[j];
				op[j+1] = op[j];
			}
			else{

				break;
			}
			
		}
		qc[j+1] = tmp_qc;
			op[j+1] = tmp_op;
	}
	for(i=0;i<8;i++){
		printf("%d\t%d\n",op[i],qc[i]);
	}
}

