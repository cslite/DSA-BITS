exe : List.o main.o
	gcc -o exe List.o main.o

list.o : lList.c List.h
	gcc -c -g List.c

main.o : main.c List.h
	gcc -c -g main.c

clean:
	rm *.o

run:
	./exe
