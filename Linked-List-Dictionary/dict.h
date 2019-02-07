struct rcnode{
	int r;
	int c;
	struct rcnode *next;
};

typedef struct rcnode rcnode;

struct wordnode{
	char *word;
	struct wordnode *next;
	rcnode *rc;
	int sz;
};

typedef struct wordnode wordnode;

struct dict{
	wordnode *head;
	int size;
};

typedef struct dict dict;


int insert(dict *db, char *word, int rno, int cno);
int deleteAll(dict *db, char *word);
dict *constructDict(char *filename);
void printAll(dict *db);
