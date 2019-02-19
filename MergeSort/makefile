exe : msort.o driver.o iter_msort.o
	gcc -o exe msort.o driver.o iter_msort.o

exe2 : msort.o driver.o rec_msort.o
	gcc -o exe2 msort.o driver.o rec_msort.o

msort.o : msort.c msort.h
	gcc -c msort.c

rec_msort.o : rec_msort.c msort.h
	gcc -c rec_msort.c

iter_msort.o : iter_msort.c msort.h
	gcc -c iter_msort.c

driver.o : driver.c msort.h
	gcc -c driver.c
