exe : tree.o driver.o extras.o
	gcc -o exe tree.o driver.o extras.o

extras.o : extras.c extras.h
	gcc -g -c extras.c

tree.o : tree.c tree.h extras.h
	gcc -g -c tree.c

driver.c : driver.c tree.h extras.h
	gcc -g -c driver.c
