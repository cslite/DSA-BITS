#include<stdio.h>
#include<stdlib.h>
#include "employee.h"
#include<string.h>
employee create_emp(char *name, int empid){
	employee e1;
	strcpy(e1.name,name);
	e1.empid = empid;
	return e1;
}

void print_emp_arr(employee *e, int sz){
	for(int i=0;i<sz;i++){
		printf("[%s:%d]\n",e[i].name,e[i].empid);
	}
}

int getkey(employee *arr, int idx){
	return arr[idx].empid;
}
