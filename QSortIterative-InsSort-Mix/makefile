exe: stack.o quicksort.o driver.o insertionsort.o employee.o mixsort.o
	gcc -o exe stack.o employee.o quicksort.o insertionsort.o mixsort.o driver.o

employee.o : employee.c employee.h
	gcc -g -c employee.c

insertionsort.o : insertionsort.c insertionsort.h employee.h
	gcc -g -c insertionsort.c

stack.o : stack.h stack.c
	gcc -g -c stack.c

quicksort.o : quicksort.h stack.h quicksort.c employee.h
	gcc -g -c quicksort.c

mixsort.o : mixsort.h quicksort.h insertionsort.h employee.h mixsort.c
	gcc -g -c mixsort.c

driver.o : driver.c quicksort.h insertionsort.h employee.h
	gcc -g -c driver.c
