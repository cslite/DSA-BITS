#include<stdio.h>
#include<stdlib.h>
#include "employee.h"
#include "insertionsort.h"


void isort(employee *arr, int lo, int hi){
	if(lo >= hi)
		return;
	int tmp_hi = lo+1;
	for(;tmp_hi<=hi;tmp_hi++){
		employee tmp = arr[tmp_hi];
		int i = tmp_hi-1;
		while(arr[i].empid > tmp.empid){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = tmp;
	}
}
