#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dict.h"

int insert(dict *db, char *word, int rno, int cno){
	if(db== NULL)
		return -1;
	if(db->head == NULL){
		wordnode *tmp = (wordnode *)(malloc(sizeof(wordnode)));
		tmp->word = word;
		tmp->sz = 1;
		tmp->rc = (rcnode *)(malloc(sizeof(rcnode)));
		tmp->rc->r = rno;
		tmp->rc->c = cno;
		tmp->rc->next = NULL;
		tmp->next = NULL;
		db->head = tmp;
		(db->size)++;
		return 1;
	}
		
	wordnode *ptr = db->head;
	int r = strcmp(word,ptr->word);
	if(r<0){
		//word is smaller than the first word
		wordnode *tmp = (wordnode *)(malloc(sizeof(wordnode)));
		tmp->word = word;
		tmp->sz = 1;
		tmp->rc = (rcnode *)(malloc(sizeof(rcnode)));
		tmp->rc->r = rno;
		tmp->rc->c = cno;
		tmp->rc->next = NULL;
		tmp->next = ptr;
		db->head = tmp;
		(db->size)++;
		return 1;
	}
	else if(r == 0){
		//word is same as the first word
		rcnode *trc = ptr->rc;
		while(trc->next != NULL){
			trc = trc->next;
		}
		trc->next = (rcnode *)(malloc(sizeof(rcnode)));
		trc->next->r = rno;
		trc->next->c = cno;
		trc->next->next = NULL;
		(ptr->sz)++;
		return 1;
	}
	else{
		while(ptr->next != NULL){
			
			r = strcmp(word,ptr->next->word);
			if(r>0){
				//word is bigger than next word in the list
				ptr = ptr->next;
			}
			else if(r<0){
				//word is smaller than the next word in the list
				wordnode *tmp = (wordnode *)(malloc(sizeof(wordnode)));
				tmp->word = word;
				tmp->sz = 1;
				tmp->rc = (rcnode *)(malloc(sizeof(rcnode)));
				tmp->rc->r = rno;
				tmp->rc->c = cno;
				tmp->rc->next = NULL;
				tmp->next = ptr->next;
				ptr->next = tmp;
				(db->size)++;
				return 1;
			}
			else{
				//word is already in the list, is equal to next word
				ptr = ptr->next;
				rcnode *trc = ptr->rc;
				while(trc->next != NULL){
					trc = trc->next;
				}
				trc->next = (rcnode *)(malloc(sizeof(rcnode)));
				trc->next->r = rno;
				trc->next->c = cno;
				trc->next->next = NULL;
				(ptr->sz)++;
				return 1;
			}
		}
		wordnode *tmp = (wordnode *)(malloc(sizeof(wordnode)));
		tmp->word = word;
		tmp->sz = 1;
		tmp->rc = (rcnode *)(malloc(sizeof(rcnode)));
		tmp->rc->r = rno;
		tmp->rc->c = cno;
		tmp->rc->next = NULL;
		tmp->next = NULL;
		ptr->next = tmp;
		(db->size)++;
		return 1;
	}
}

int deleteAll(dict *db, char *word){
	if(db == NULL || db->head == NULL)
		return -1;
	wordnode *ptr = db->head;
	if(strcmp(ptr->word,word)==0){
		db->head = ptr->next;
		(db->size)--;
		return 1;
	}
	else{
		while(ptr->next != NULL){
			if(strcmp(ptr->next->word,word) == 0){
				//next word is to be deleted
				ptr->next = ptr->next->next;
				(db->size)--;
				return 1;
			}
		}
		return -1;
	}
}

void printRC(rcnode *head){
	if(head == NULL)
		return;
	rcnode *ptr = head;
	printf("[");
	while(ptr!= NULL){
		printf(" (%d,%d)",ptr->r,ptr->c);
		ptr = ptr->next;
	}
	printf(" ]\n");
}

void printAll(dict *db){
	if(db==NULL || db->head == NULL)
		return;
	wordnode *ptr = db->head;
	while(ptr!=NULL){
		printf("%s(%d)\n",ptr->word,ptr->sz);
		printRC(ptr->rc);
		ptr = ptr->next;
	}
}

dict *constructDict(char *filename){
	FILE *fptr = fopen(filename, "r");
	if(fptr == NULL)
		return NULL;
	char *w = (char *)(calloc(15,sizeof(char)));
	int ctr = 0;
	int r = 1;
	int c = 1;
	dict *db = (dict *)(malloc(sizeof(dict)));
	while(1){
		char ch = fgetc(fptr);
		if((ch >= 'a' && ch<= 'z') || (ch>='A' && ch<='Z')){
			//it is a valid alphabet
			w[ctr++] = ch;
		}
		else if(ch == ' ' || ch == '\t'){
			//word got complete insert it
			if(ctr != 0){
				insert(db,w,r,c);
				c++;
				w = (char *)(calloc(15,sizeof(char)));
				ctr = 0;
			}
		}
		else if(ch == '\n'){
			if(ctr!=0){
				insert(db,w,r,c);
				r++;
				c=1;
				w = (char *)(calloc(15,sizeof(char)));
				ctr = 0;
			}
		}
		else if(ch == EOF){
			if(ctr!=0){
				insert(db,w,r,c);
			}
			break;
		}
		//ignore other characters
	}
	return db;
}
