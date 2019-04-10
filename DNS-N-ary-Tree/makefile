exe : driver.o dns.o
	gcc -o exe driver.o dns.o

dns.o : dns.c dns.h
	gcc -g -c dns.c

driver.o : driver.c dns.h
	gcc -g -c driver.c

