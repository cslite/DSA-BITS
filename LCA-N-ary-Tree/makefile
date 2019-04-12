exe : lca.o driver.o
	gcc -o exe driver.o lca.o

lca.o : lca.h lca.c
	gcc -g -c lca.c

driver.o : lca.h driver.c
	gcc -g -c driver.c
