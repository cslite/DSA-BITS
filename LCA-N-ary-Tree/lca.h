struct node{
	char *key;
	struct node **child;
	int noc;
	int sz;
};

typedef struct node node;

struct pathArr{
	char **p;
	int sz;
};

typedef struct pathArr pathArr;


void find_lca(node *root, char *p1, char *p2);
void readData(node *root, int n);
node *create_node();
