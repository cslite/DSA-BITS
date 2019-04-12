exe : main.o lower.o list2array.o readdata.o insertion.o merge.o
	gcc -o exe main.o lower.o list2array.o readdata.o insertion.o merge.o

main.o : main.c node.h
	gcc -c main.c

lower.o : lower.c node.h
	gcc -c lower.c

insertion.o : insertion.c node.h
	gcc -c insertion.c

list2array.o : list2array.c node.h
	gcc -c list2array.c

readdata.o : readdata.c node.h
	gcc -c readdata.c

merge.o : merge.c node.h
	gcc -c merge.c
