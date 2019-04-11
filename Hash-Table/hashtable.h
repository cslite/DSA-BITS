struct student{
	char name[9];
	long id;
};

typedef struct student student;

struct node{
	student *s;
	struct node *next;
};

typedef struct node node;

struct ht{
	node *arr;
	int tableLength;
	int elementCount;
	float loadFactor;
	int insertionTime;
	int queryingTime;
};

typedef struct ht ht;

int hashfun(student *s, int option);

int hashfun1(char *key,int tableLength);
int hashfun2(char *key,int tableLength);
int hashfun3(char *key,int tableLength);
int hashfun4(char *key,int tableLength);
int hashfun5(long key,int tableLength);
int hashfun6(long key,int tableLength);
int hashfun7(long key,int tableLength);
int hashfun8(long key,int tableLength);

student *records;

ht *readRecords(int numRecords);	//returns an array of HTs
void readQueries(int numQueries, ht *arr);
void findInsertionComplexity(ht *arr);
void findQueryComplexity(ht *arr);
