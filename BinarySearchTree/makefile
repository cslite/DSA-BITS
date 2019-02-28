exe_rec : btree.o search_rec.o driver.o
	gcc -o exe_rec btree.o search_rec.o driver.o

exe_iter : btree.o search_iter.o driver.o
	gcc -o exe_iter btree.o search_iter.o driver.o

btree.o : btree.c btree.h
	gcc -c btree.c

search_rec.o : search_rec.c btree.h
	gcc -c search_rec.c

search_iter.o : search_iter.c btree.h
	gcc -c search_iter.c

driver.o : driver.c btree.h
	gcc -c driver.c
