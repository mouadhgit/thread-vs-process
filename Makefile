main: thread.o process.o

thread.o: thread.c
	gcc thread.c -o thread.o -lpthread

process.o: process.c
	gcc -o process.o process.c

clean:
	rm *.o main

