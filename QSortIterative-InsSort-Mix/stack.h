struct pair{
	int lo;
	int hi;
};

typedef struct pair pair;

struct stack{
	pair *s;
	int count;
	int size;
};

typedef struct stack stack;

stack newStack();

int isEmpty(stack s);

void doubleStack(stack *st);

stack push(stack st, pair ele);

pair pop(stack *st);

pair top(stack st);
