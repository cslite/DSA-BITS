exe: driver.o avl.o
	gcc -o exe driver.o avl.o

driver.o : avl.h driver.c
	gcc -g -c driver.c

avl.o : avl.c avl.h
	gcc -g -c avl.c
