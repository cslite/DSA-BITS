exe : hashtable.o driver.o
	gcc -o exe driver.o hashtable.o

hashtable.o : hashtable.c hashtable.h
	gcc -c hashtable.c

driver.o : driver.c hashtable.h
	gcc -c driver.c
