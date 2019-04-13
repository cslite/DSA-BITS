exe : radix.o driver.o
	gcc -o exe radix.o driver.o
radix.o : radix.c radix.h
	gcc -c radix.c
driver.o : driver.c radix.h
	gcc -c driver.c
