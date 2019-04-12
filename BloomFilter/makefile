exe : bf.o driver.o
	gcc -o exe bf.o driver.o

bf.o : bf.c bf.h
	gcc -c bf.c

driver.o : driver.c bf.h
	gcc -c driver.c
