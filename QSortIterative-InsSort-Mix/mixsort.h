#include "employee.h"

struct dub2{
	double ist;
	double qst;
};
typedef struct dub2 dub2;

void mixSort(employee *arr, int lo, int hi, int cutoff);
// dub2 testRun(employee *arr, int lo, int hi, int cutoff);
int estimateCutoff(employee *arr, int lo, int hi, double difflimit);
