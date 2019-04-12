struct BloomFilter{
	char *bf;	//the array to store 0s and 1s
	int size;
};

typedef struct BloomFilter BloomFilter;

BloomFilter createBF(int size);
int hashval(char *str, int option, int tsz);
void add(BloomFilter b, char *str);
bool check(BloomFilter b, char *str);
void insertData(BloomFilter b, char *filename);
