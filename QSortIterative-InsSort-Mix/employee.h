struct employee{
	char name[11];
	int empid;
};

typedef struct employee employee;

employee create_emp(char *name, int empid);
void print_emp_arr(employee *e, int sz);
int getkey(employee *arr, int idx);
