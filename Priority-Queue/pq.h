typedef struct priority_queue{
	int *h;
	int max_len;
	int sz;
} priority_queue;

priority_queue create_pq(int ele);
int maximum(priority_queue pq);
int extract_max(priority_queue *pq);
void increase_key(priority_queue pq, int idx, int k);
void insert(priority_queue *pq, int key);
