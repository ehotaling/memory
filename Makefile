all: memory-test

memory-test: memory.o memory-test.o
	gcc memory.o memory-test.o -o memory-test

memory.o: memory.c memory.h
	gcc -c memory.c

memory-test.o: memory-test.c memory.h
	gcc -c memory-test.c

clean:
	rm -f *.o memory-test
