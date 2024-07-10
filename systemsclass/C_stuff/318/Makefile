

CFLAGS= -std=gnu99

all:		program

library.o:	library.c
	gcc $(CFLAGS) -c -o library.o library.c

main.o:		main.c
	gcc $(CFLAGS) -c -o main.o main.c

program:	main.o	library.o
	gcc -o program main.o library.o

clean:
	rm -f *.o program