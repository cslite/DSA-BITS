struct node{
	char *key;	//contains key value of the node
	struct node **child;	//array of pointers to child nodes
	int noc;	//no. of children actually stored in the child array
	int sz;	//size of the array of pointers
};

typedef struct node node;

struct sdarr{
	char **sd;
	int sz;
};

typedef struct sdarr sdarr;

node *create_node();
void readData(node *root, int n);
void lookup(node *root, char *name);

