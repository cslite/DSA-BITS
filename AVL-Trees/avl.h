struct node{
	int key;
	struct node *left;
	struct node *right;
	int h;
	int balance : 2;	//bit-field
};

typedef struct node node;

struct rangeSet{
	node **arr;
	int size;
};

typedef struct rangeSet rangeSet;

node *add(node *root, int key);
node *find(node *root, int key);
node *find_min(node *root);
node *delete(node *root, int key);
node *rankQuery(node *root, int k);
rangeSet rangeQuery(node *root, int k1, int k2);
void printTree(node* curr,int depth);
node *add_avl(node *root, int key);
