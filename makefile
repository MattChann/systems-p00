ifeq ($(DEBUG), true)
	CC = gcc -g
else 
	CC = gcc
endif 

dependencies = library_methods.o list_methods.o

all: main.o $(dependencies)
	$(CC) -o program main.o $(dependencies)

main.o: main.c library_headers.h list_headers.h
	$(CC) -c main.c

library_methods.o: library_methods.c library_headers.h
	$(CC) -c library_methods.c 

list_methods.o: list_methods.c list_headers.h
	$(CC) -c list_methods.c 

val:
	valgrind --leak-check=yes --track-origins=yes ./program

run: 
	./program

clean:
	rm *.o
	rm program