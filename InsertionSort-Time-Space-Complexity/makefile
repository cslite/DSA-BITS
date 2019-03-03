ip1: card.o insertionSort.o measure.o driver.o input1.o
	gcc -o exe1 card.o input1.o measure.o insertionSort.o driver.o

ip2: card.o insertionSort.o measure.o driver.o input2.o
	gcc -o exe2 card.o input2.o measure.o insertionSort.o driver.o

input1.o : input1.c card.h
	gcc -c input1.c

input2.o : input2.c card.h
	gcc -c input2.c

card.o : card.c card.h
	gcc -c card.c

insertionSort.o : insertionSort.c insertionSort.h
	gcc -c insertionSort.c

measure.o : measure.c measure.h
	gcc -c measure.c

driver.o : driver.c card.h
	gcc -c driver.c
