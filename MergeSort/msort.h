struct student{
	char *name;
	float cgpa;
};

typedef struct student student;

struct stud_record{
	student *s;
	int size;
};

typedef struct stud_record stud_record;

void merge(student ls1[], int sz1, student ls2[], int sz2, student ls[]);
void printData(stud_record sr);
stud_record readData(char *filename);
void mergeSort(student ls[], int sz);
