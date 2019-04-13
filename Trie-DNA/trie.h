struct node{
	struct node **next;
};

typedef struct node node;

enum dna{A,C,G,T};

node *newNode();
void insert(node *root, char *seq);
node *createTrie(char *seq);
void printTrie(node *root);
int find(node *root, char *str);

