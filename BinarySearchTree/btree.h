struct node{
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
};

typedef struct node node;

struct btree{
	node *root;
	int size;
};

typedef struct btree btree;


void inOrderWalk(node *root);
void preOrderWalk(node *root);
void postOrderWalk(node *root);
node *searchKey(node *root, int key);

node *getMin(node *root);
node *getMax(node *root);
node *succ(node *ptr);
node *pred(node *ptr);

node *createNode(int key);
void insertNode(btree *bt, node *n);
btree createTree(int *arr, int sz);
node *deleteNode(btree *bt, node *n);
