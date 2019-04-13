exe : trie.o driver.o
	gcc -o exe trie.o driver.o

trie.o : trie.c trie.h
	gcc -g -c trie.c

driver.o : driver.c trie.h
	gcc -g -c driver.c
