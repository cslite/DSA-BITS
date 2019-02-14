
struct cardinfo{
	char cno[17];
	char bankcode[6];
	int exp_m;
	int exp_y;	
	char fname[20];
	char lname[20];
};
typedef struct cardinfo cardinfo;

struct record{
	cardinfo *arr;
	int size;
};
typedef struct record record;

cardinfo genci(char *str);
record insert_data(char *filename);
void printci(cardinfo ci);
void printRecord(record r);


